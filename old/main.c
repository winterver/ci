#include "ci.h"
#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
# include <io.h>
#else
# include <unistd.h>
#endif

enum {
    READ, WRITE, OPEN, CLOSE, LSEEK,
    MALLOC, FREE, MEMSET, MEMCPY, EXIT,
    PRINTF, SCANF, 
};

int64_t ci_syscall(int num, int64_t* p, int c) {
    #define ARG1 p[c-1]
    #define ARG2 p[c-2]
    #define ARG3 p[c-3]
    #define ARG4 p[c-4]
    #define ARG5 p[c-5]
    #define ARG6 p[c-6]

    switch(num) {
    case READ: return read(ARG1, (void*)ARG2, ARG3);
    case WRITE: return write(ARG1, (void*)ARG2, ARG3);
    case OPEN: return open((char*)ARG1, ARG2);
    case CLOSE: return close(ARG1);
    case LSEEK: return lseek(ARG1, ARG2, ARG3);

    case MALLOC: return (int64_t)malloc(ARG1);
    case FREE: free((void*)ARG1); break;
    case MEMSET: return (int64_t)memset((void*)ARG1, ARG2, ARG3);
    case MEMCPY: return (int64_t)memcpy((void*)ARG1, (void*)ARG2, ARG3);
    case EXIT: exit(ARG1); break;

    case PRINTF: return printf((char*)ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);
    case SCANF: return scanf((char*)ARG1, ARG2, ARG3, ARG4, ARG5, ARG6);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("usage: ci source.c\n");
        return 0;
    }

    int fd;
    if ((fd = open(argv[1], 0)) < 0) {
        printf("failed to open %s\n", argv[1]);
        return -1;
    }
    int len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char* buf = malloc(len+1);
    if ((len = read(fd, buf, len)) < 0) {
        printf("failed to read %s\n", argv[1]);
        return -1;
    }
    buf[len] = 0;

    ci_init(0, 0, 0, 0);

    ci_register_syscall(READ, CI_INT, "read");
    ci_register_syscall(WRITE, CI_INT, "write");
    ci_register_syscall(OPEN, CI_INT, "open");
    ci_register_syscall(CLOSE, CI_INT, "close");
    ci_register_syscall(LSEEK, CI_INT, "lseek");
    ci_register_enum("SEEK_SET", SEEK_SET);
    ci_register_enum("SEEK_CUR", SEEK_CUR);
    ci_register_enum("SEEK_END", SEEK_END);

    ci_register_syscall(MALLOC, CI_VOID + CI_PTR, "malloc");
    ci_register_syscall(FREE, CI_VOID, "free");
    ci_register_syscall(MEMSET, CI_VOID + CI_PTR, "memset");
    ci_register_syscall(MEMCPY, CI_VOID + CI_PTR, "memcpy");
    ci_register_syscall(EXIT, CI_VOID, "exit");

    ci_register_syscall(PRINTF, CI_INT, "printf");
    ci_register_syscall(SCANF, CI_INT, "scanf");

    struct ci_program prog;
    if (ci_compile(&prog, buf)) {
        ci_perror();
        return -1;
    }

    ci_exit();
 
    int ax = ci_execute(&prog, 0, argc-1, (signed char**)argv+1);
    printf("exit(%d)\n", ax);
 
	return 0;
}
