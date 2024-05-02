%expect 1

%{

#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char* error, ...);

struct astnode;
struct astnode* root;
struct astnode* mknode(char* value,
                       struct astnode* inner,
                       struct astnode* next);
struct astnode* backof(struct astnode* node);

%}

%union{
    char* string;
    int pointer;
    struct astnode {
        char* value;
        struct astnode* inner;
        struct astnode* next;
    } *node;
}

%token<string> IDENTIFIER STRING CONSTANT
%token VOID CHAR SHORT INT LONG FLOAT DOUBLE ENUM STRUCT
%token IF ELSE DO WHILE FOR CONTINUE BREAK RETURN SIZEOF
%token ADDA SUBA MULA DIVA MODA ANDA ORA XORA LE GE
%token EQ NE AND OR SHL SHR SHLA SHRA INC DEC
%token ELLIPSIS
%token UNCLOSED_BLOCK_COMMENT
%token UNKNOWN_CHARACTER

%type<node> translation_unit external_declaration
%type<node> declaration type_specifier init_declarator_list
%type<node> init_declarator declarator pointer function
%type<node> parameter_list parameter_declaration
%type<node> statement compound_statement
%type<node> block_item_list block_item
%type<node> expression
%type<node> expression_statement selection_statement
%type<node> iteration_statement jump_statement

%start start

%%

start
    :                   { root = NULL; }
    | translation_unit  { root = $1; }
    ;

translation_unit
	: external_declaration
        { $$ = mknode("translation_unit", $1, NULL); }
	| translation_unit external_declaration
        { backof($1->inner)->next = $2; }
	;

external_declaration
	: declaration
	| function
	;

declaration
	: type_specifier ';'
        { $$ = mknode("declaration", $1, NULL); }
	| type_specifier init_declarator_list ';'
        {
            $1->next = $2;
            $$ = mknode("declaration", $1, NULL);
        }
	;

type_specifier
	: VOID      { $$ = mknode("type_specifier", mknode("void", NULL, NULL), NULL); }
	| CHAR      { $$ = mknode("type_specifier", mknode("char", NULL, NULL), NULL); }
	| SHORT     { $$ = mknode("type_specifier", mknode("short", NULL, NULL), NULL); }
	| INT       { $$ = mknode("type_specifier", mknode("int", NULL, NULL), NULL); }
	| LONG      { $$ = mknode("type_specifier", mknode("long", NULL, NULL), NULL); }
	| FLOAT     { $$ = mknode("type_specifier", mknode("float", NULL, NULL), NULL); }
	| DOUBLE    { $$ = mknode("type_specifier", mknode("double", NULL, NULL), NULL); }
	;

init_declarator_list
	: init_declarator
        { $$ = mknode("init_declarator_list", $1, NULL); }
	| init_declarator_list ',' init_declarator
        { backof($1->inner)->next = $3; }
	;

init_declarator
	: declarator
        { $$ = mknode("init_declarator", $1, NULL); }
	| declarator '=' assignment_expression
        {
            $1->next = mknode("initializer", NULL, NULL);
            $$ = mknode("init_declarator", $1, NULL);
        }
	;

declarator
	: IDENTIFIER
        {
            struct astnode* value = mknode($1, NULL, NULL);
            struct astnode* identifier = mknode("IDENTIFIER", value, NULL);
            $$ = mknode("declarator", identifier, NULL);
        }
	| pointer IDENTIFIER
        {
            struct astnode* value = mknode($2, NULL, NULL);
            struct astnode* identifier = mknode("IDENTIFIER", value, NULL);
            backof($1)->next = identifier;
            $$ = mknode("declarator", $1, NULL);
        }

	;

pointer
	: '*'           { $$ = mknode("pointer", NULL, NULL); }
	| pointer '*'   { $$ = mknode("pointer", NULL, $1); }
	;

function
	: type_specifier declarator '(' ')' compound_statement
        {
            $2->next = mknode("parameter_list", NULL, $5);
            $1->next = $2;
            $$ = mknode("function", $1, NULL);
        }
	| type_specifier declarator '(' VOID ')' compound_statement
        {
            $2->next = mknode("parameter_list", NULL, $6);
            $1->next = $2;
            $$ = mknode("function", $1, NULL);
        }
	| type_specifier declarator '(' parameter_list ')' compound_statement
        {
            $4->next = $6;
            $2->next = $4;
            $1->next = $2;
            $$ = mknode("function", $1, NULL);
        }
    ;

parameter_list
	: parameter_declaration
        { $$ = mknode("paramter_list", $1, NULL); }
	| parameter_list ',' parameter_declaration
        { backof($1->inner)->next = $3; }
	;

parameter_declaration
	: type_specifier declarator
        {
            $1->next = $2;
            $$ = mknode("parameter_declaration", $1, NULL);
        }
	;

primary_expression
	: IDENTIFIER
	| STRING
	| CONSTANT
	| '(' expression ')'
	;

postfix_expression
	: primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression INC
	| postfix_expression DEC
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC unary_expression
	| DEC unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	;

unary_operator
	: '&'
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

type_name
    : type_specifier
    | type_specifier pointer
    ;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression SHL additive_expression
	| shift_expression SHR additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE shift_expression
	| relational_expression GE shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression EQ relational_expression
	| equality_expression NE relational_expression
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: '='
	| MULA
	| DIVA
	| MODA
	| ADDA
	| SUBA
	| SHLA
	| SHRA
	| ANDA
	| XORA
	| ORA
	;

expression
	: assignment_expression
        { $$ = mknode("expression", NULL, NULL); }
	;

statement
	: compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

compound_statement
	: '{' '}'
        { $$ = mknode("compound_statement", NULL, NULL); }
	| '{' block_item_list '}'
        { $$ = mknode("compound_statement", $2, NULL); }
	;

block_item_list
	: block_item
	| block_item_list block_item
        { backof($1)->next = $2; }
	;

block_item
	: declaration
	| statement
	;

expression_statement
	: ';'               { /* TODO */ }
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement
        {
            $3->next = $5;
            $$ = mknode("if", $3, NULL);
        }
	| IF '(' expression ')' statement ELSE statement
        {
            $5->next = $7;
            $3->next = $5;
            $$ = mknode("if", $3, NULL);
        }
	;

iteration_statement
	: WHILE '(' expression ')' statement
        {
            $3->next = $5;
            $$ = mknode("while", $3, NULL);
        }
	| DO statement WHILE '(' expression ')' ';'
        {
            $2->next = $5;
            $$ = mknode("do_while", $2, NULL);
        }
	| FOR '(' expression_statement expression_statement ')' statement
        {
            struct astnode* cond = mknode("condition", $4, $6);
            struct astnode* init = mknode("initial", $3, cond);
            $$ = mknode("for", init, NULL);
        }
	| FOR '(' expression_statement expression_statement expression ')' statement
        {
            struct astnode* iter = mknode("iteration", $5, $7);
            struct astnode* cond = mknode("condition", $4, iter);
            struct astnode* init = mknode("initial", $3, cond);
            $$ = mknode("for", init, NULL);
        }
	| FOR '(' declaration expression_statement ')' statement
        {
            struct astnode* cond = mknode("condition", $4, $6);
            struct astnode* init = mknode("initial", $3, cond);
            $$ = mknode("for", init, NULL);
        }
	| FOR '(' declaration expression_statement expression ')' statement
        {
            struct astnode* iter = mknode("iteration", $5, $7);
            struct astnode* cond = mknode("condition", $4, iter);
            struct astnode* init = mknode("initial", $3, cond);
            $$ = mknode("for", init, NULL);
        }
	;

jump_statement
	: CONTINUE ';'              { $$ = mknode("continue", NULL, NULL); }
	| BREAK ';'                 { $$ = mknode("break", NULL, NULL); }
	| RETURN ';'                { $$ = mknode("return", NULL, NULL); }
	| RETURN expression ';'     { $$ = mknode("return", $2, NULL); }
	;

%%

struct astnode* mknode(char* value,
                       struct astnode* inner,
                       struct astnode* next)
{
    struct astnode* an = malloc(sizeof(struct astnode));
    an->value = value;
    an->inner = inner;
    an->next = next;
    return an;
}


struct astnode* backof(struct astnode* node)
{
    if (node == NULL || node->next == NULL)
    {
        return node;
    }
    return backof(node->next);
}

void print_astnode(struct astnode* node)
{
    static int indent = 0;
    if (node == NULL)
    {
        indent--;
        return;
    }
    for (int i = 0; i < indent; i++)
    {
        putchar(' ');
    }

    puts(node->value);
    indent++;
    print_astnode(node->inner);
    print_astnode(node->next);
}

int main()
{
    yyparse();
    print_astnode(root);
    return 0;
}
