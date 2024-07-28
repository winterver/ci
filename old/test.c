void f233(){}

int main() {
    char* name = "test.c";

    int fd;
    if ((fd = open(name, 0)) < 0) {
        printf("failed to open %s\n", name);
        return -1;
    }
    int len = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);

    char* buf = malloc(len+1);
    if ((len = read(fd, buf, len)) < 0) {
        printf("failed to read %s\n", name);
        return -1;
    }
    buf[len] = 0;

    printf("%s\n", buf);
    free(buf);
    return 0;
}
