#ifndef _CI_H_
#define _CI_H_

#include <stdint.h>
#define char int8_t
#define short int16_t
#define int int32_t
#define long int64_t

typedef struct {
    const char* name;
    int scope;
    int kind;
    int type;
    int val;
} ci_id_t;

struct ci_program {
    int main;
    int textlen;
    int datalen;
    char* text;
    char* data;
};

int ci_compile(struct ci_program* prog, char* src, ci_id_t* sys, int num);
int ci_execute(struct ci_program* prog, int stksize);
int ci_debug(struct ci_program* prog, int stksize);
void ci_perror();

#undef long
#undef int
#undef short
#undef char

enum { CI_VOID = 1, CI_CHAR, CI_SHORT, CI_INT, CI_LONG, CI_PTR = 256 };
int64_t ci_syscall(int num, int64_t* params, int count);

#endif
