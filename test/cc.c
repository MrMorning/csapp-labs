int foo(int x) {
    printf("%d", x);
}
main() {
    char c = 1>(int)2147483648;
    foo(c);
}
