# 1 "cc.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "cc.c"
int foo(int x) {
    printf("%d", x);
}
main() {
    char c = 1>(int)2147483648;
    foo(c);
}
