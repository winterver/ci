/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_CI_TAB_H_INCLUDED
# define YY_YY_SRC_CI_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    STRING = 259,                  /* STRING  */
    CONSTANT = 260,                /* CONSTANT  */
    VOID = 261,                    /* VOID  */
    CHAR = 262,                    /* CHAR  */
    SHORT = 263,                   /* SHORT  */
    INT = 264,                     /* INT  */
    LONG = 265,                    /* LONG  */
    FLOAT = 266,                   /* FLOAT  */
    DOUBLE = 267,                  /* DOUBLE  */
    ENUM = 268,                    /* ENUM  */
    STRUCT = 269,                  /* STRUCT  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    DO = 272,                      /* DO  */
    WHILE = 273,                   /* WHILE  */
    FOR = 274,                     /* FOR  */
    CONTINUE = 275,                /* CONTINUE  */
    BREAK = 276,                   /* BREAK  */
    RETURN = 277,                  /* RETURN  */
    SIZEOF = 278,                  /* SIZEOF  */
    ADDA = 279,                    /* ADDA  */
    SUBA = 280,                    /* SUBA  */
    MULA = 281,                    /* MULA  */
    DIVA = 282,                    /* DIVA  */
    MODA = 283,                    /* MODA  */
    ANDA = 284,                    /* ANDA  */
    ORA = 285,                     /* ORA  */
    XORA = 286,                    /* XORA  */
    LE = 287,                      /* LE  */
    GE = 288,                      /* GE  */
    EQ = 289,                      /* EQ  */
    NE = 290,                      /* NE  */
    AND = 291,                     /* AND  */
    OR = 292,                      /* OR  */
    SHL = 293,                     /* SHL  */
    SHR = 294,                     /* SHR  */
    SHLA = 295,                    /* SHLA  */
    SHRA = 296,                    /* SHRA  */
    INC = 297,                     /* INC  */
    DEC = 298,                     /* DEC  */
    ELLIPSIS = 299,                /* ELLIPSIS  */
    UNCLOSED_BLOCK_COMMENT = 300,  /* UNCLOSED_BLOCK_COMMENT  */
    UNKNOWN_CHARACTER = 301        /* UNKNOWN_CHARACTER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "src\\ci.y"

    char* string;
    int pointer;
    struct astnode {
        char* value;
        struct astnode* inner;
        struct astnode* next;
    } *node;

#line 120 "src\\ci.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_CI_TAB_H_INCLUDED  */
