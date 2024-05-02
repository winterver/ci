#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <malloc.h>
#include <setjmp.h>
#include <ctype.h>
#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

#define char int8_t
#define short int16_t
#define int int32_t
#define long int64_t

#ifndef MAX_TABLE
# define MAX_TABLE 1024
#endif
#ifndef MAX_TEXT
# define MAX_TEXT 65536
#endif
#ifndef MAX_DATA
# define MAX_DATA 4096
#endif
#ifndef MAX_BREAK
# define MAX_BREAK 128
#endif

static int no;
static const char* err;
static jmp_buf jmp;

static void error(const char* str) {
    err = str;
    longjmp(jmp, 1);
}

#define STRINGIFY(str) #str
#define INTERNAL_ERROR() \
    error(__FILE__ " (" STRINGIFY(__LINE__) "): INTERNAL ERROR")

static char escape(char c) {
    if (c == 't') { return '\t'; }
    else if (c == 'r') { return '\r'; }
    else if (c == 'n') { return '\n'; }
    else if (c == '0') { return '\0'; }
    else if (c == '\'') { return '\''; }
    else if (c == '\"') { return '\"'; }
    else if (c == '\\') { return '\\'; }
    else { error("unknown escape sequence"); }
    return 0;
}

enum {
    Id = 128, Num, Str,
    Void, Char, Short, Int, Long, Enum,
    If, Else, Do, While, For, Continue, Break, Return, Sizeof,
    Assign, Cond, Lor, Lan, Or, Xor, And, Eq, Ne, Lt, Gt,
    Le, Ge, Shl, Shr, Add, Sub, Mul, Div, Mod, Inc, Dec, Brak,
    AddA, SubA, MulA, DivA, ModA, AndA, OrA, XorA, ShlA, ShrA,
};

enum { Sys = 1, Fun, Glo, Loc, /* Enum */ };
enum { VOID = 1, CHAR, SHORT, INT, LONG, PTR = 256 };

enum {
    GLO = 1, LEA, IMM, PSH,
    LC, LS, LI, LL, SC, SS, SI, SL,
    ADD, SUB, MUL, DIV, MOD, AND, OR, XOR,
    LT, GT, LE, EQ, NE, GE, SHL, SHR,
    JMP, BZ, BNZ, SYS, JSR, ENT, LEV, ADJ,
};

static const char *p;
static int tk;
static long val;
static const char* str;

static char *text, *ct;
static char *data, *cd;
#define e8 (*(char**)check_text(sizeof(char)))
#define e16 (*(short**)check_text(sizeof(short)))
#define e32 (*(int**)check_text(sizeof(int)))
#define e64 (*(long**)check_text(sizeof(long)))
#define d8 (*(char**)check_data(sizeof(char)))
#define d16 (*(short**)check_data(sizeof(short)))
#define d32 (*(int**)check_data(sizeof(int)))
#define d64 (*(long**)check_data(sizeof(long)))

static void** check_text(int sz) {
    if ((ct+sz) > (text+MAX_TEXT)) {
        error("text segment too short");
    }
    return (void**)&ct;
}

static void** check_data(int sz) {
    if ((cd+sz) > (data+MAX_DATA)) {
        error("data segment too short");
    }
    return (void**)&cd;
}

static int prefix(const char* s) {
    const char* pp = p;
    while (*p && *p == *s) { p++; s++; }
    if (*s == 0) { return 1; }
    else { p = pp; return 0; }
}

static int idcmp(const char* s1, const char* s2) {
    while ((isalnum(*s1) || *s1 == '_')
        && (isalnum(*s2) || *s2 == '_')
        && *s1 == *s2) { s1++; s2++; }
    int b1 = !(isalnum(*s1) || *s1 == '_');
    int b2 = !(isalnum(*s2) || *s2 == '_');
    return b1 && b2;
}

static void next() {
    while ((tk = *p)) {
        if (strchr(" \t\r", *p)) { p++; }
        else if (strchr("\n", *p)) { p++; no++; }
        else if (prefix("#")) { while (*p && *p != '\n') { p++; } }
        else if (prefix("//")) { while (*p && *p != '\n') { p++; } }
        else if (prefix("/*")) { while (*p && !prefix("*/")) { no += *p++ == '\n'; } }
        else if (prefix("<<=")) { tk = ShlA; return; }
        else if (prefix(">>=")) { tk = ShrA; return; }
        else if (prefix("<<")) { tk = Shl; return; }
        else if (prefix(">>")) { tk = Shr; return; }
        else if (prefix("+=")) { tk = AddA; return; }
        else if (prefix("-=")) { tk = SubA; return; }
        else if (prefix("*=")) { tk = MulA; return; }
        else if (prefix("/=")) { tk = DivA; return; }
        else if (prefix("%=")) { tk = ModA; return; }
        else if (prefix("&=")) { tk = AndA; return; }
        else if (prefix("|=")) { tk = OrA; return; }
        else if (prefix("^=")) { tk = XorA; return; }
        else if (prefix("<=")) { tk = Le; return; }
        else if (prefix(">=")) { tk = Ge; return; }
        else if (prefix("!=")) { tk = Ne; return; }
        else if (prefix("==")) { tk = Eq; return; }
        else if (prefix("&&")) { tk = Lan; return; }
        else if (prefix("||")) { tk = Lor; return; }
        else if (prefix("++")) { tk = Inc; return; }
        else if (prefix("--")) { tk = Dec; return; }
        else if (prefix("+")) { tk = Add; return; }
        else if (prefix("-")) { tk = Sub; return; }
        else if (prefix("*")) { tk = Mul; return; }
        else if (prefix("/")) { tk = Div; return; }
        else if (prefix("%")) { tk = Mod; return; }
        else if (prefix("&")) { tk = And; return; }
        else if (prefix("|")) { tk = Or; return; }
        else if (prefix("^")) { tk = Xor; return; }
        else if (prefix("<")) { tk = Lt; return; }
        else if (prefix(">")) { tk = Gt; return; }
        else if (prefix("[")) { tk = Brak; return; }
        else if (prefix("?")) { tk = Cond; return; }
        else if (prefix("=")) { tk = Assign; return; }
        else if (strchr("~!](){}.,:;", *p)) { p++; return; }
        else if (isalpha(*p) || *p == '_') { 
            const char* pp = p;
            while (isalnum(*p) || *p == '_') { p++; }
            if (idcmp("void", pp)) { tk = Void; return; }
            else if (idcmp("char", pp)) { tk = Char; return; }
            else if (idcmp("short", pp)) { tk = Short; return; }
            else if (idcmp("int", pp)) { tk = Int; return; }
            else if (idcmp("long", pp)) { tk = Long; return; }
            else if (idcmp("enum", pp)) { tk = Enum; return; }
            else if (idcmp("if", pp)) { tk = If; return; }
            else if (idcmp("else", pp)) { tk = Else; return; }
            else if (idcmp("do", pp)) { tk = Do; return; }
            else if (idcmp("while", pp)) { tk = While; return; }
            else if (idcmp("for", pp)) { tk = For; return; }
            else if (idcmp("continue", pp)) { tk = Continue; return; }
            else if (idcmp("break", pp)) { tk = Break; return; }
            else if (idcmp("return", pp)) { tk = Return; return; }
            else if (idcmp("sizeof", pp)) { tk = Sizeof; return; }
            else { str = pp; tk = Id; return; }
        }
        else if (isdigit(*p)) {
            val = 0;
            if (*p == '0') {
                p++;
                if (strchr("xX", *p)) {
                    const char* pp = ++p;
                    while (isxdigit(*p) && (tk = *p++)) {
                        val = val * 16 + (tk & 15) + (tk >= 'A') * 9;
                    }
                    if (pp == p) { error("bad hexadecimal literal"); }
                }
                else if (strchr("bB", *p)) {
                    const char* pp = ++p;
                    while (strchr("01", *p)) {
                        val = val * 2 + *p++ - '0';
                    }
                    if (pp == p) { error("bad binary literal"); }
                }
                else {
                    while ('0' <= *p && *p <= '7') {
                        val = val * 8 + *p++ - '0';
                    }
                }
            }
            else {
                while (isdigit(*p)) {
                    val = val * 10 + *p++ - '0';
                }
            }
            tk = Num;
            return;
        }
        else if (*p == '\'') {
            if (*++p == '\'') { error("bad char literal"); }
            if (*p == '\0') { error("bad char literal"); }
            if (*p == '\\') { val = escape(*++p); p++; }
            else { val = *p++; }
            if (*p++ != '\'') { error("bad char literal"); }
            tk = Num;
            return;
        }
        else if (*p == '\"') {
            // TODO forbid multiline string
            // TODO string literal concatenation
            val = d8 - data;
            while (*++p && *p != '\"') {
                *d8++ = *p == '\\' ? escape(*++p) : *p;
            }
            if (*p++ != '\"') { error("unexpected EOF"); }
            *d8++ = 0;
            tk = Str;
            return;
        }
        else { error("unknown character"); }
    }
}

typedef struct {
    const char* name;
    int scope;
    int kind;
    int type;
    int val;
} id_t;

static id_t* table;
static int tblen;
static int scope;

static id_t* find_id() {
    for (int i = tblen; i-- > 0;) {
        if (idcmp(str, table[i].name)) {
            return &table[i];
        }
    }
    error("undefined identifier");
    return NULL;
}

static id_t* new_id() {
    for (int i = tblen; i-- > 0;) {
        if (scope > table[i].scope) { break; }
        if (idcmp(str, table[i].name)) {
            if (scope == table[i].scope) {
                error("duplicate identifier");
            }
        }
    }
    if (tblen >= MAX_TABLE) {
        error("max identifier exceeded");
    }
    id_t* id = &table[tblen++];
    memset(id, 0, sizeof(id_t));
    id->scope = scope;
    id->name = str;
    return id;
}

int ty;
int loc;
int sol; // start of loop
int **brks,
    **cbrk;

static int size_of(int type) {
    if (type == CHAR) { return sizeof(char); }
    else if (type == SHORT) { return sizeof(short); }
    else if (type == INT) { return sizeof(int); }
    else if (type == LONG) { return sizeof(long); }
    else if (type > PTR) { return sizeof(void*); }
    else { INTERNAL_ERROR(); return 0; }
}

static void expr(int lev) {
    if (tk == Str) { *e8++ = GLO; *e32++ = val; ty = CHAR + PTR; next(); }
    else if (tk == Num) { *e8++ = IMM; *e64++ = val; ty = INT; next(); }
    else if (tk == Sizeof) {
        next();
        if (tk == '(') { next(); } else { error("'(' expected"); }
        int bt = INT;
        if (tk == Void) { bt = VOID; next(); }
        else if (tk == Char) { bt = CHAR; next(); }
        else if (tk == Short) { bt = SHORT; next(); }
        else if (tk == Int) { bt = INT; next(); }
        else if (tk == Long) { bt = LONG; next(); }           
        else if (tk == Enum) {
            next();
            if (tk != Id) { error("bad enum specifier"); }
            next();
        }
        else { error("bad type specifier"); }
        ty = bt;
        while (tk == Mul) { next(); ty += PTR; }
        if (ty == VOID) { error("sizeof(void) is invalid"); }
        if (tk == ')') { next(); } else { error("')' expected"); }
        *e8++ = IMM;
        *e64++ = size_of(ty);
        ty = INT;
    }
    else if (tk == Id) {
        id_t* d = find_id();
        next();
        if (tk == '(') {
            next();
            int t;
            for (t = 0; tk != ')'; t++) {
                expr(Assign);
                *e8++ = PSH;
                if (tk == ',') { next(); }
            }
            next();
            if (d->kind == Sys) { *e8++ = SYS; *e8++ = d->val; }
            else if (d->kind == Fun) { *e8++ = JSR; *e32++ = d->val; }
            else { error("bad function call"); }
            if (t) { *e8++ = ADJ; *e8++ = t; }
            ty = d->type;
        }
        else if (d->kind == Enum) {
            *e8++ = IMM;
            *e64++ = d->val;
            ty = INT;
        }
        else {
            if (d->kind == Glo) { *e8++ = GLO; }
            else if (d->kind == Loc) { *e8++ = LEA; }
            else { INTERNAL_ERROR(); }
            *e32++ = d->val;
            // emit_load_by_type
            switch (size_of(d->type)) {
            case 1: *e8++ = LC; break;
            case 2: *e8++ = LS; break;
            case 4: *e8++ = LI; break;
            case 8: *e8++ = LL; break;
            default: INTERNAL_ERROR();
            }
            ty = d->type;
        }
    }
    else if (tk == '(') {
        next();
        if (
            tk == Void
            || tk == Char
            || tk == Short
            || tk == Int
            || tk == Long
            || tk == Enum
        ) {
            int bt = INT;
            if (tk == Void) { bt = VOID; next(); }
            else if (tk == Char) { bt = CHAR; next(); }
            else if (tk == Short) { bt = SHORT; next(); }
            else if (tk == Int) { bt = INT; next(); }
            else if (tk == Long) { bt = LONG; next(); }           
            else if (tk == Enum) {
                next();
                if (tk != Id) { error("bad enum specifier"); }
                next();
            }
            else { error("bad type specifier"); }
            ty = bt;
            while (tk == Mul) { next(); ty += PTR; }
            if (tk == ')') { next(); } else { error("')' expected"); }
            int t = ty;
            expr(Inc);
            ty = t;
        }
        else {
            expr(Assign);
            if (tk == ')') { next(); } else { error("')' expected"); }
        }
    }
    else if (tk == Mul) {
        next();
        expr(Inc);
        if (ty < PTR) { error("bad dereference"); }
        ty -= PTR;
        // emit_load_by_type
        switch (size_of(ty)) {
        case 1: *e8++ = LC; break;
        case 2: *e8++ = LS; break;
        case 4: *e8++ = LI; break;
        case 8: *e8++ = LL; break;
        default: INTERNAL_ERROR();
        }
    }
    else if (tk == And) {
        next();
        expr(Inc);
        switch (e8[-1]) {
        case LC: case LS: case LI: case LL: e8--; break;
        default: error("bad address-of"); break;
        }
        ty += PTR;
    }
    else if (tk == '!') {
        next();
        expr(Inc);
        *e8++ = PSH;
        *e8++ = IMM;
        *e64++ = 0;
        *e8++ = EQ;
        ty = LONG;
    }
    else if (tk == '~') {
        next();
        expr(Inc);
        *e8++ = PSH;
        *e8++ = IMM;
        *e64++ = -1;
        *e8++ = XOR;
        ty = LONG;
    }
    else if (tk == Add) {
        next();
        expr(Inc);
        ty = LONG;
    }
    else if (tk == Sub) {
        next();
        *e8++ = IMM;
        if (tk == Enum) {
            *e64++ = -val;
            next();
        }
        else {
            *e64++ = -1;
            *e8++ = PSH;
            expr(Inc);
            *e8++ = MUL;
        }
        ty = LONG;
    }
    else if (tk == Inc || tk == Dec) {
        int t = tk;
        next();
        expr(Inc);
        // is_left & emit_load_by_type
        switch (e8[-1]) {
        case LC: e8[-1] = PSH; *e8++ = LC; break;
        case LS: e8[-1] = PSH; *e8++ = LS; break;
        case LI: e8[-1] = PSH; *e8++ = LI; break;
        case LL: e8[-1] = PSH; *e8++ = LL; break;
        default: error("bad pre-increment"); break;
        }
        *e8++ = PSH;
        *e8++ = IMM;
        *e64++ = ty < PTR ? 1 : size_of(ty - PTR);
        *e8++ = (t == Inc) ? ADD : SUB;
        // emit_store_by_type
        switch (size_of(ty)) {
        case 1: *e8++ = SC; break;
        case 2: *e8++ = SS; break;
        case 4: *e8++ = SI; break;
        case 8: *e8++ = SL; break;
        default: INTERNAL_ERROR();
        }
    }
    else { error("bad expression"); }

    while (tk >= lev) {
        int t = ty;
        if (tk == Assign) {
            next();
            switch (e8[-1]) {
            case LC: case LS: case LI: case LL: e8[-1] = PSH; break;
            default: error("bad assignment");
            }
            expr(Assign);
            // emit_store_by_type
            switch (size_of(t)) {
            case 1: *e8++ = SC; break;
            case 2: *e8++ = SS; break;
            case 4: *e8++ = SI; break;
            case 8: *e8++ = SL; break;
            default: INTERNAL_ERROR();
            }
            ty = t;
        }
        else if (tk == Cond) {
            next();
            *e8++ = BZ;
            int* d = e32++;
            expr(Assign);
            if (tk != ':') { error("bad conditional expression"); }
            next();
            *d = e8 - text + 5;
            *e8++ = JMP;
            d = e32++;
            expr(Cond);
            *d = e8 - text;
        }
        else if (tk == Lor) {
            next();
            *e8++ = BNZ;
            int* d = e32++;
            expr(Lan);
            *d = e8 - text;
            ty = LONG;
        }
        else if (tk == Lan) {
            next();
            *e8++ = BZ;
            int* d = e32++;
            expr(Or);
            *d = e8 - text;
            ty = LONG;
        }
        else if (tk == Or) {
            next();
            *e8++ = PSH;
            expr(Xor);
            *e8++ = OR;
            ty = LONG;
        }
        else if (tk == Xor) {
            next();
            *e8++ = PSH;
            expr(And);
            *e8++ = XOR;
            ty = LONG;
        }
        else if (tk == And) {
            next();
            *e8++ = PSH;
            expr(Eq);
            *e8++ = AND;
            ty = LONG;
        }
        else if (tk == Eq) {
            next();
            *e8++ = PSH;
            expr(Lt);
            *e8++ = EQ;
            ty = LONG;
        }
        else if (tk == Ne) {
            next();
            *e8++ = PSH;
            expr(Lt);
            *e8++ = NE;
            ty = LONG;
        }
        else if (tk == Lt) {
            next();
            *e8++ = PSH;
            expr(Shl);
            *e8++ = LT;
            ty = LONG;
        }
        else if (tk == Gt) {
            next();
            *e8++ = PSH;
            expr(Shl);
            *e8++ = GT;
            ty = LONG;
        }
        else if (tk == Le) {
            next();
            *e8++ = PSH;
            expr(Shl);
            *e8++ = LE;
            ty = LONG;
        }
        else if (tk == Ge) {
            next();
            *e8++ = PSH;
            expr(Shl);
            *e8++ = GE;
            ty = LONG;
        }
        else if (tk == Shl) {
            next();
            *e8++ = PSH;
            expr(Add);
            *e8++ = SHL;
            ty = LONG;
        }
        else if (tk == Shr) {
            next();
            *e8++ = PSH;
            expr(Add);
            *e8++ = SHR;
            ty = LONG;
        }
        else if (tk == Add) {
            next();
            *e8++ = PSH;
            expr(Mul);
            if ((ty = t) > PTR) {
                *e8++ = PSH;
                *e8++ = IMM;
                *e64++ = size_of(ty - PTR);
                *e8++ = MUL;
            }
            *e8++ = ADD;
        }
        else if (tk == Sub) {
            next();
            *e8++ = PSH;
            expr(Mul);
            if (t > PTR && t == ty) {
                *e8++ = SUB;
                *e8++ = PSH;
                *e8++ = IMM;
                *e64++ = size_of(ty - PTR);
                *e8++ = DIV;
                ty = LONG;
            }
            else if ((ty = t) > PTR) {
                *e8++ = PSH;
                *e8++ = IMM;
                *e64++ = size_of(ty - PTR);
                *e8++ = MUL;
                *e8++ = SUB;
            }
            else { *e8++ = SUB; }
        }
        else if (tk == Mul) {
            next();
            *e8++ = PSH;
            expr(Inc);
            *e8++ = MUL;
            ty = LONG;
        }
        else if (tk == Div) {
            next();
            *e8++ = PSH;
            expr(Inc);
            *e8++ = DIV;
            ty = LONG;
        }
        else if (tk == Mod) {
            next();
            *e8++ = PSH;
            expr(Inc);
            *e8++ = MOD;
            ty = LONG;
        }
        else if (tk == Inc || tk == Dec) {
            // is_left & emit_load_by_type
            switch (e8[-1]) {
            case LC: e8[-1] = PSH; *e8++ = LC; break;
            case LS: e8[-1] = PSH; *e8++ = LS; break;
            case LI: e8[-1] = PSH; *e8++ = LI; break;
            case LL: e8[-1] = PSH; *e8++ = LL; break;
            default: error("bad post-increment"); break;
            }   
            *e8++ = PSH;
            *e8++ = IMM;
            *e64++ = ty < PTR ? 1 : size_of(ty - PTR);
            *e8++ = (tk == Inc) ? ADD : SUB;
            // emit_store_by_type
            switch (size_of(ty)) {
            case 1: *e8++ = SC; break;
            case 2: *e8++ = SS; break;
            case 4: *e8++ = SI; break;
            case 8: *e8++ = SL; break;
            default: INTERNAL_ERROR();
            }
            *e8++ = PSH;
            *e8++ = IMM;
            *e64++ = ty < PTR ? 1 : size_of(ty - PTR);
            *e8++ = (tk == Inc) ? SUB : ADD;
            next();
        }
        else if (tk == Brak) {
            next();
            *e8++ = PSH;
            expr(Assign);
            if (tk != ']') { error("']' expected"); }
            next();
            if (t < PTR) { error("bad subscription"); }
            *e8++ = PSH;
            *e8++ = IMM;
            *e64++ = size_of(t - PTR);
            *e8++ = MUL;
            *e8++ = ADD;
            // emit_load_by_type
            switch (size_of(t - PTR)) {
            case 1: *e8++ = LC; break;
            case 2: *e8++ = LS; break;
            case 4: *e8++ = LI; break;
            case 8: *e8++ = LL; break;
            default: INTERNAL_ERROR();
            }
            ty = t - PTR;
        }
        else { INTERNAL_ERROR(); }
    }
}

static void stmt() {
    if (
        tk == Void
        || tk == Char
        || tk == Short
        || tk == Int
        || tk == Long
        || tk == Enum
    ) {
        int bt = INT;
        if (tk == Void) { bt = VOID; next(); }
        else if (tk == Char) { bt = CHAR; next(); }
        else if (tk == Short) { bt = SHORT; next(); }
        else if (tk == Int) { bt = INT; next(); }
        else if (tk == Long) { bt = LONG; next(); }           
        else if (tk == Enum) {
            next();
            if (tk == Id) { next(); }
            if (tk == '{') {
                next();
                int i = 0;
                while (tk != '}') {
                    if (tk != Id) { error("bad enumerator"); }
                    next();
                    if (tk == Assign) {
                        next();
                        if (tk != Num) { error("bad enum initializer"); }
                        i = val;
                        next();
                    }
                    id_t* id = new_id();
                    id->kind = Enum;
                    id->val = i++;
                    if (tk == ',') { next(); }
                }
                next();
            }
        }

        while (tk != ';') {
            ty = bt;
            while (tk == Mul) { next(); ty += PTR; }
            if (ty == VOID) { error("bad local variable declaration"); }
            if (tk != Id) { error("bad local variable declaration"); }

            /*
            char* bp = p,
                bstr = str;
            int btk = tk,
                bno = no,
                bval = val;
            */

            loc -= size_of(ty);
            id_t* par = new_id();
            par->kind = Loc;
            par->type = ty;
            par->val = loc;
            next();
            if (tk == ',') { next(); }
        }
    }
    else if (tk == If) {
        next();
        if (tk == '(') { next(); } else { error("'(' expected"); }
        expr(Assign);
        if (tk == ')') { next(); } else { error("')' expected"); }
        *e8++ = BZ;
        int* b = e32++;
        stmt();
        if (tk == Else) {
            next();
            *b = e8 - text + 5;
            *e8++ = JMP;
            b = e32++;
            stmt();
        }
        *b = e8 - text;
    }
    else if (tk == While) {
        next();
        int bsol = sol;
        int** bcbrk = cbrk;

        sol = e8 - text; // start of loop
        if (tk == '(') { next(); } else { error("'(' expected"); }
        expr(Assign);
        if (tk == ')') { next(); } else { error("')' expected"); }
        *e8++ = BZ;
        int* b = e32++; // end of loop
        stmt();
        *e8++ = JMP;
        *e32++ = sol;
        *b = e8 - text;

        while (cbrk-- > bcbrk) {
            **cbrk = *b;
        }
        cbrk = bcbrk;
        sol = bsol;
    }
    else if (tk == Continue) {
        next();
        if (sol == 0) { error("'continue' outside of loop"); }
        if (tk != ';') { error("';' expected"); }
        next();
        *e8++ = JMP;
        *e32++ = sol;
    }
    else if (tk == Break) {
        next();
        if (sol == 0) { error("'break' outside of loop"); }
        if ((cbrk - brks) >= MAX_BREAK) { error("too many breaks"); }
        if (tk != ';') { error("';' expected"); }
        next();
        *e8++ = JMP;
        *cbrk++ = e32++;
    }
    else if (tk == Return) {
        next();
        if (tk != ';') { expr(Assign); }
        *e8++ = LEV;
        if (tk != ';') { error("';' expected"); }
        next();
    }
    else if (tk == '{') {
        next();
        scope++;
        int len = tblen;
        while (tk != '}') { stmt(); }
        tblen = len;
        scope--;
        next();
    }
    else if (tk == ';') {
        next();
    }
    else {
        expr(Assign);
        if (tk != ';') { error("';' expected"); }
        next();
    }
}

struct program {
    int main;
    int textlen;
    int datalen;
    char* text;
    char* data;
};

int compile(struct program* prog, char* src, id_t* sys, int num) {
    if (setjmp(jmp)) {
        return -1;
    }

    no = 1;
    p = src;

    table = malloc(MAX_TABLE * sizeof(id_t));
    tblen = 0;
    scope = 1;
    while (tblen < num) {
        table[tblen].val = sys[tblen].val;
        table[tblen].type = sys[tblen].type;
        table[tblen].name = sys[tblen].name;
        table[tblen].scope = 0;
        table[tblen].kind = Sys;
        tblen++;
    }

    text = ct = malloc(MAX_TEXT);
    data = cd = malloc(MAX_DATA);
    memset(data, 0, MAX_DATA);

    brks = cbrk = malloc(MAX_BREAK * sizeof(int*));
    sol = 0;

    next();
    while (tk) {
        int bt = INT;
        if (tk == Void) { bt = VOID; next(); }
        else if (tk == Char) { bt = CHAR; next(); }
        else if (tk == Short) { bt = SHORT; next(); }
        else if (tk == Int) { bt = INT; next(); }
        else if (tk == Long) { bt = LONG; next(); }
        else if (tk == Enum) {
            next();
            if (tk == Id) { next(); }
            if (tk == '{') {
                next();
                int i = 0;
                while (tk != '}') {
                    if (tk != Id) { error("bad enumerator"); }
                    next();
                    if (tk == Assign) {
                        next();
                        if (tk != Num) { error("bad enum initializer"); }
                        i = val;
                        next();
                    }
                    id_t* id = new_id();
                    id->kind = Enum;
                    id->val = i++;
                    if (tk == ',') { next(); }
                }
                next();
            }
        }
        while (tk != ';' && tk != '}') {
            ty = bt;
            while (tk == Mul) { next(); ty += PTR; }
            if (tk != Id) { error("bad global declaration"); }
            id_t* id = new_id();
            id->type = ty;
            next();

            if (tk == '(') {
                id->kind = Fun;
                id->val = e8 - text;
                next();

                scope++;
                int len = tblen;
                loc = 8; // bp - stack,
                         // instruction next to jsr - prog.text
                while (tk != ')') {
                    bt = INT;
                    if (tk == Void) { bt = VOID; next(); }
                    else if (tk == Char) { bt = CHAR; next(); }
                    else if (tk == Short) { bt = SHORT; next(); }
                    else if (tk == Int) { bt = INT; next(); }
                    else if (tk == Long) { bt = LONG; next(); }           
                    else if (tk == Enum) {
                        next();
                        if (tk != Id) { error("bad enum specifier"); }
                        next();
                    }
                    else { error("bad parameter declaration"); }

                    ty = bt;
                    while (tk == Mul) { next(); ty += PTR; }
                    if (ty == VOID) { error("bad parameter declaration"); }
                    if (tk != Id) { error("bad parameter declaration"); }
                    id_t* par = new_id();
                    par->kind = Loc;
                    par->type = ty;
                    par->val = loc;
                    loc += sizeof(long);
                    next();
                    if (tk == ',') { next(); }
                }
                next();
                
                if (tk != '{') { error("bad function definition"); }
                next();

                loc = 0;
                *e8++ = ENT;
                int* stack = e32++;
                while (tk != '}') { stmt(); }
                if (e8[-1] != LEV) { *e8++ = LEV; }
                *stack = loc;

                tblen = len;
                scope--;
            }
            else {
                if (id->type == VOID) {
                    error("bad global variable declaration");
                }
                id->kind = Glo;
                id->val = d8 - data;
                d8 += size_of(id->type);
            }
            if (tk == ',') { next(); }
        }
        next();
    }

    id_t* main = NULL;
    for (int i = tblen; i-- > 0;) {
        if (idcmp("main", table[i].name)) {
            main = &table[i];
            break;
        }
    }
    if (!main || main->kind != Fun) {
        error("main() is not found");
    }

    prog->main = main->val;
    prog->textlen = e8 - text;
    prog->datalen = d8 - data;
    prog->text = malloc(e8 - text);
    prog->data = malloc(d8 - data);
    memcpy(prog->text, text, e8 - text);
    memcpy(prog->data, data, d8 - data);
    free(text);
    free(data);
    free(table);
    free(brks);
    return 0;
}

long syscall(int num, long* params, int count);
int execute(struct program* prog, int stksize, int debug) {
    if (debug) {
        char* pc = prog->text;
        #define pc8 (*(char**)&pc)
        #define pc16 (*(short**)&pc)
        #define pc32 (*(int**)&pc)
        #define pc64 (*(long**)&pc)
        while (pc < (prog->text + prog->textlen)) {
            printf("%04llX: ", pc - prog->text);
            switch(*pc8++) {
            default: printf("Illegal opcode: %X\n", pc8[-1]); return -1;
            case GLO: printf("\tGLO 0x%X\n", *pc32++); break;
            case LEA: printf("\tLEA %d\n", *pc32++); break;
            case IMM: printf("\tIMM %lld\n", *pc64++); break;
            case SYS: printf("\tSYS %d\n", *pc8++); break;
            case BZ: printf("\tBZ 0x%X\n", *pc32++); break;
            case BNZ: printf("\tBNZ 0x%X\n", *pc32++); break;
            case JMP: printf("\tJMP 0x%X\n", *pc32++); break;
            case JSR: printf("\tJSR 0x%X\n", *pc32++); break;
            case ENT: printf("\tENT %d\n", *pc32++); break;
            case ADJ: printf("\tADJ %d\n", *pc8++); break;
            case PSH: printf("\tPSH\n"); break;
            case LEV: printf("\tLEV\n"); break;
            case LC: printf("\tLC\n"); break;
            case LS: printf("\tLS\n"); break;
            case LI: printf("\tLI\n"); break;
            case LL: printf("\tLL\n"); break;
            case SC: printf("\tSC\n"); break;
            case SS: printf("\tSS\n"); break;
            case SI: printf("\tSI\n"); break;
            case SL: printf("\tSL\n"); break;
            case ADD: printf("\tADD\n"); break;
            case SUB: printf("\tSUB\n"); break;
            case MUL: printf("\tMUL\n"); break;
            case DIV: printf("\tDIV\n"); break;
            case MOD: printf("\tMOD\n"); break;
            case AND: printf("\tAND\n"); break;
            case OR: printf("\tOR\n"); break;
            case XOR: printf("\tXOR\n"); break;
            case EQ: printf("\tEQ\n"); break;
            case NE: printf("\tNE\n"); break;
            case LT: printf("\tLT\n"); break;
            case GT: printf("\tGT\n"); break;
            case LE: printf("\tLE\n"); break;
            case GE: printf("\tGE\n"); break;
            case SHL: printf("\tSHL\n"); break;
            case SHR: printf("\tSHR\n"); break;
            }
        }
        #undef pc64
        #undef pc32
        #undef pc16
        #undef pc8
        printf("\n");
    }

    char* pc = prog->text + prog->main;
    #define pc8 (*(char**)&pc)
    #define pc16 (*(short**)&pc)
    #define pc32 (*(int**)&pc)
    #define pc64 (*(long**)&pc)

    char* stack = malloc(stksize);
    char* sp = stack + stksize;
    char* bp = stack + stksize;
    #define sp8 (*(char**)&sp)
    #define sp16 (*(short**)&sp)
    #define sp32 (*(int**)&sp)
    #define sp64 (*(long**)&sp)

    long ax;

    #define debugf(...) if (debug) { printf(__VA_ARGS__); }

    while (1) {
        if (sp < (stack+8)) { printf("Stack overflow\n"); goto End; }
        debugf("%04llX: ", pc - prog->text);
        switch(*pc8++) {
        default:
            printf("Illegal opcode: %X\n", (uint8_t)pc8[-1]);
            goto End;
        case GLO:
            debugf("\tGLO 0x%X\n", *pc32);
            ax = (long)(prog->data + *pc32++);
            break;
        case LEA:
            debugf("\tLEA %d\n", *pc32);
            ax = (long)(bp + *pc32++);
            break;
        case IMM:
            debugf("\tIMM %lld\n", *pc64);
            ax = *pc64++;
            break;
        case SYS:
            debugf("\tSYS %d\n", *pc8);
            int count = pc[1] == ADJ ? pc[2] : 0;
            ax = syscall(*pc8++, (long*)sp, count);
            break;
        case BZ:
            debugf("\tBZ 0x%X\n", *pc32);
            if (!ax) { pc = prog->text + *pc32; }
            else { pc32++; }
            break;
        case BNZ:
            debugf("\tBNZ 0x%X\n", *pc32);
            if (ax) { pc = prog->text + *pc32; }
            else { pc32++; }
            break;
        case JMP:
            debugf("\tJMP 0x%X\n", *pc32);
            pc = prog->text + *pc32;
            break;
        case JSR:
            debugf("\tJSR 0x%X\n", *pc32);
            *--sp32 = pc - prog->text + 4;
            pc = prog->text + *pc32;
            break;
        case ENT:
            debugf("\tENT %d\n", *pc32);
            *--sp32 = bp - stack;
            bp = sp;
            sp += *pc32++;
            break;
        case ADJ:
            debugf("\tADJ %d\n", *pc8);
            sp64 += *pc8++;
            break;
        case PSH:
            debugf("\tPSH\n");
            *--sp64 = ax;
            break;
        case LEV:
            debugf("\tLEV\n");
            sp = bp;
            bp = stack + *sp32++;
            // check if return from main
            if (bp == (stack+stksize)) {
                // break; // breaks switch, not while
                goto End;
            }
            pc = prog->text + *sp32++;
            break;
        case LC:
            debugf("\tLC\n");
            ax = *(char*)ax;
            break;
        case LS:
            debugf("\tLS\n");
            ax = *(short*)ax;
            break;
        case LI:
            debugf("\tLI\n");
            ax = *(int*)ax;
            break;
        case LL:
            debugf("\tLL\n");
            ax = *(long*)ax;
            break;
        case SC:
            debugf("\tSC\n");
            *(char*)*sp64++ = ax;
            break;
        case SS:
            debugf("\tSS\n");
            *(short*)*sp64++ = ax;
            break;
        case SI:
            debugf("\tSI\n");
            *(int*)*sp64++ = ax;
            break;
        case SL:
            debugf("\tSL\n");
            *(long*)*sp64++ = ax;
            break;
        case ADD:
            debugf("\tADD\n");
            ax = *sp64++ + ax;
            break;
        case SUB:
            debugf("\tSUB\n");
            ax = *sp64++ - ax;
            break;
        case MUL:
            debugf("\tMUL\n");
            ax = *sp64++ * ax;
            break;
        case DIV:
            debugf("\tDIV\n");
            ax = *sp64++ / ax;
            break;
        case MOD:
            debugf("\tMOD\n");
            ax = *sp64++ % ax;
            break;
        case AND:
            debugf("\tAND\n");
            ax = *sp64++ & ax;
            break;
        case OR:
            debugf("\tOR\n");
            ax = *sp64++ | ax;
            break;
        case XOR:
            debugf("\tXOR\n");
            ax = *sp64++ ^ ax;
            break;
        case EQ:
            debugf("\tEQ\n");
            ax = *sp64++ == ax;
            break;
        case NE:
            debugf("\tNE\n");
            ax = *sp64++ != ax;
            break;
        case LT:
            debugf("\tLT\n");
            ax = *sp64++ < ax;
            break;
        case GT:
            debugf("\tGT\n");
            ax = *sp64++ > ax;
            break;
        case LE:
            debugf("\tLE\n");
            ax = *sp64++ <= ax;
            break;
        case GE:
            debugf("\tGE\n");
            ax = *sp64++ >= ax;
            break;
        case SHL:
            debugf("\tSHL\n");
            ax = *sp64++ << ax;
            break;
        case SHR:
            debugf("\tSHR\n");
            ax = *sp64++ >> ax;
            break;
        }
    }
    #undef debugf
    #undef sp64
    #undef sp32
    #undef sp16
    #undef sp8
    #undef pc64
    #undef pc32
    #undef pc16
    #undef pc8
End:
    free(stack);
    return ax;
}

enum {
    READ,
    WRITE,
    OPEN,
    CLOSE,
    MALLOC,
    FREE,
    MEMSET,
    MEMCPY,
    PRINTF,
    EXIT,
};
static id_t sys[] = {
    { .val = READ, .type = INT, .name = "read" },
    { .val = WRITE, .type = INT, .name = "write" },
    { .val = OPEN, .type = INT, .name = "open" },
    { .val = CLOSE, .type = INT, .name = "close" },
    { .val = MALLOC, .type = INT, .name = "malloc" },
    { .val = FREE, .type = INT, .name = "free" },
    { .val = MEMSET, .type = INT, .name = "memset" },
    { .val = MEMCPY, .type = INT, .name = "memcpy" },
    { .val = PRINTF, .type = INT, .name = "printf" },
    { .val = EXIT, .type = INT, .name = "exit" },
};
#define NUM (sizeof(sys)/sizeof(sys[0]))

long syscall(int num, long* p, int c) {
    switch(num) {
    case READ: return read(p[c-1], (void*)p[c-2], p[c-3]);
    case WRITE: return write(p[c-1], (void*)p[c-2], p[c-3]);
    case OPEN: return open((char*)p[c-1], p[c-2]);
    case CLOSE: return close(p[c-1]);
    case MALLOC: return (long)malloc(p[c-1]);
    case FREE: free((void*)p[c-1]);
    case MEMSET: return (long)memset((void*)p[c-1], p[c-2], p[c-3]);
    case MEMCPY: return (long)memcpy((void*)p[c-1], (void*)p[c-2], p[c-3]);
    case PRINTF: return printf((char*)p[c-1], p[c-2], p[c-3], p[c-4], p[c-5], p[c-6], p[c-7]);
    case EXIT: exit(p[c-1]);
    }
}

int main() {
    char buf[BUFSIZ*10];
    int n = fread(buf, 1, BUFSIZ*10, stdin);
    buf[n] = 0;

    struct program prog;
    if (compile(&prog, buf, sys, NUM)) {
        printf("(%d): %s\n", no, err);
        return -1;
    }
 
    int ax = execute(&prog, 4096, 0);
    printf("exit(%d)\n", ax);
 
	return 0;
}
