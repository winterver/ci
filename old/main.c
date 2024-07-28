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

int64_t ci_syscall(int num, int64_t* p) {
    switch(num) {
    case READ: return read(p[0], (void*)p[1], p[2]);
    case WRITE: return write(p[0], (void*)p[1], p[2]);
    case OPEN: return open((char*)p[0], p[1]);
    case CLOSE: return close(p[0]);
    case LSEEK: return lseek(p[0], p[1], p[2]);

    case MALLOC: return (int64_t)malloc(p[0]);
    case FREE: free((void*)p[0]); break;
    case MEMSET: return (int64_t)memset((void*)p[0], p[1], p[2]);
    case MEMCPY: return (int64_t)memcpy((void*)p[0], (void*)p[1], p[2]);
    case EXIT: exit(p[0]); break;

    case PRINTF: return printf((char*)p[0], p[1], p[2], p[3], p[4], p[5]);
    case SCANF: return scanf((char*)p[0], p[1], p[2], p[3], p[4], p[5]);
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
