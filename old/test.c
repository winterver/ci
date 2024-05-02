int rfib(int n) {
    if (n < 3) return 1;
    return rfib(n-1) + rfib(n-2);
}

int fib(int n) {
    int a, b;
    a = b = 1;
    while (n-- > 2) {
        int t;
        t = a + b;
        b = a;
        a = t;
    }
    return a;
}

int main() {
    //printf("rfib(34) = %d\n", rfib(34));
    printf("fib(34) = %d\n", fib(34));
    return 0;
}
