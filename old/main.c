#include "ci.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

enum {
    READ, WRITE, OPEN, CLOSE,
    MALLOC, FREE, MEMSET, MEMCPY,
    PRINTF, EXIT,
};
static ci_id_t sys[] = {
    { .val = READ, .type = CI_INT, .name = "read" },
    { .val = WRITE, .type = CI_INT, .name = "write" },
    { .val = OPEN, .type = CI_INT, .name = "open" },
    { .val = CLOSE, .type = CI_INT, .name = "close" },
    { .val = MALLOC, .type = CI_INT, .name = "malloc" },
    { .val = FREE, .type = CI_INT, .name = "free" },
    { .val = MEMSET, .type = CI_INT, .name = "memset" },
    { .val = MEMCPY, .type = CI_INT, .name = "memcpy" },
    { .val = PRINTF, .type = CI_INT, .name = "printf" },
    { .val = EXIT, .type = CI_INT, .name = "exit" },
};
#define NUM (sizeof(sys)/sizeof(sys[0]))

int64_t ci_syscall(int num, int64_t* p, int c) {
    #define ARG1 p[c-1]
    #define ARG2 p[c-2]
    #define ARG3 p[c-3]
    #define ARG4 p[c-4]
    #define ARG5 p[c-5]
    #define ARG6 p[c-6]
    #define ARG7 p[c-7]

    switch(num) {
    case READ: return read(ARG1, (void*)ARG2, ARG3);
    case WRITE: return write(ARG1, (void*)ARG2, ARG3);
    case OPEN: return open((char*)ARG1, ARG2);
    case CLOSE: return close(ARG1);
    case MALLOC: return (int64_t)malloc(ARG1);
    case FREE: free((void*)ARG1);
    case MEMSET: return (int64_t)memset((void*)ARG1, ARG2, ARG3);
    case MEMCPY: return (int64_t)memcpy((void*)ARG1, (void*)ARG2, ARG3);
    case PRINTF: return printf((char*)ARG1, ARG2, ARG3, ARG4, ARG5, ARG6, ARG7);
    case EXIT: exit(ARG1);
    }
}

int main() {
    char buf[BUFSIZ*10+1];
    int n = read(0, buf, BUFSIZ*10);
    buf[n] = 0;

    struct ci_program prog;
    if (ci_compile(&prog, buf, sys, NUM)) {
        ci_perror();
        return -1;
    }
 
    int ax = ci_execute(&prog, 0);
    printf("exit(%d)\n", ax);
 
	return 0;
}
