void test(int a, int b) {
    printf("%d %d\n", a, b);
}

int main(int argc, char** argv) {
    test(1, 2);
    return 0;
    printf("%d\n", argv);
    if (argc != 2) {
        printf("usage: ci type.c <file>\n");
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

    printf("%s\n", buf);
    free(buf);
    return 0;
}
