%option noyywrap
%option nounistd
%option yylineno
%option interactive

%{

#include <stdio.h>
#include <string.h>
#include "ci.tab.h"

#ifdef _WIN32
#include <io.h>
#define strdup _strdup
#define isatty _isatty
#define fileno _fileno
#endif

void yyerror(const char* error, ...);

%}

D                                           [0-9]
L                                           [a-zA-Z_]
H                                           [a-fA-F0-9]
E                                           ([Ee][+-]?{D}+)
P                                           ([Pp][+-]?{D}+)
FS                                          (f|F)
IS                                          (l|L)

%%

"void"                                      { return VOID; }
"char"                                      { return CHAR; }
"short"                                     { return SHORT; }
"int"                                       { return INT; }
"long"                                      { return LONG; }
"float"                                     { return FLOAT; }
"double"                                    { return DOUBLE; }
"enum"                                      { return ENUM; }
"if"                                        { return IF; }
"else"                                      { return ELSE; }
"do"                                        { return DO; }
"while"                                     { return WHILE; }
"for"                                       { return FOR; }
"continue"                                  { return CONTINUE; }
"break"                                     { return BREAK; }
"return"                                    { return RETURN; }
"sizeof"                                    { return SIZEOF; }

{L}({L}|{D})*                               { yylval.string = strdup(yytext); return IDENTIFIER; }
\"(\\.|[^\\"\n])*\"                         { yylval.string = strdup(yytext); return STRING; }
'(\\.|[^\\'\n])+'                           { yylval.string = strdup(yytext); return CONSTANT; }
0[bB][01]+{IS}?                             { yylval.string = strdup(yytext); return CONSTANT; }
0[0-7]*{IS}?                                { yylval.string = strdup(yytext); return CONSTANT; }
[1-9]{D}*{IS}?                              { yylval.string = strdup(yytext); return CONSTANT; }
0[xX]{H}+{IS}?                              { yylval.string = strdup(yytext); return CONSTANT; }
{D}+{E}{FS}?                                { yylval.string = strdup(yytext); return CONSTANT; }
{D}*"."{D}+{E}?{FS}?                        { yylval.string = strdup(yytext); return CONSTANT; }
{D}+"."{D}*{E}?{FS}?                        { yylval.string = strdup(yytext); return CONSTANT; }
0[xX]{H}+{P}{FS}?                           { yylval.string = strdup(yytext); return CONSTANT; }
0[xX]{H}*"."{H}+{P}?{FS}?                   { yylval.string = strdup(yytext); return CONSTANT; }
0[xX]{H}+"."{H}*{P}?{FS}?                   { yylval.string = strdup(yytext); return CONSTANT; }

"+="                                        { return ADDA; }
"-="                                        { return SUBA; }
"*="                                        { return MULA; }
"/="                                        { return DIVA; }
"%="                                        { return MODA; }
"&="                                        { return ANDA; }
"|="                                        { return ORA; }
"^="                                        { return XORA; }
"<="                                        { return LE; }
">="                                        { return GE; }
"=="                                        { return EQ; }
"!="                                        { return NE; }
"&&"                                        { return AND; }
"||"                                        { return OR; }
"<<"                                        { return SHL; }
">>"                                        { return SHR; }
"<<="                                       { return SHLA; }
">>="                                       { return SHRA; }
"++"                                        { return INC; }
"--"                                        { return DEC; }
"..."                                       { return ELLIPSIS; }
[+\-/*%&|^!~,;:?()[\]{}<>=]                 { return *yytext; }

[ \t\r\n]                                   { }
"//"[^\n]*                                  { }
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]         { }
[/][*]                                      { return UNCLOSED_BLOCK_COMMENT; }
.                                           { return UNKNOWN_CHARACTER; }

%%

void yyerror(const char* error, ...)
{
    extern int yychar;
    if (yychar == UNCLOSED_BLOCK_COMMENT)
    {
        error = "unclosed block comment";
    }
    else if (yychar == UNKNOWN_CHARACTER)
    {
        error = "unknown character";
    }
    fprintf(stderr, "(%d): %s\n", yylineno, error);
}
