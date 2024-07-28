#ifndef _CI_H_
#define _CI_H_

#include <stdint.h>
#define char int8_t
#define short int16_t
#define int int32_t
#define long int64_t

struct ci_program {
    int main;
    int textlen;
    int datalen;
    char* text;
    char* data;
};

int ci_init(int maxtext, int maxdata, int maxtable, int maxbreak);

enum { CI_VOID = 1, CI_CHAR, CI_SHORT, CI_INT, CI_LONG, CI_PTR = 256 };
void ci_register_syscall(int num, int type, char* name);
void ci_register_enum(char* name, int val);

int ci_compile(struct ci_program* prog, char* src);
int ci_execute(struct ci_program* prog, int stksize);
int ci_debug(struct ci_program* prog, int stksize);

void ci_perror();
void ci_exit();

#undef long
#undef int
#undef short
#undef char

int64_t ci_syscall(int num, int64_t* params, int count);

#endif
