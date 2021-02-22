# 1 "b.c"
# 1 "/home/chen/coding/csapp/test//"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "b.c"
int b(int a, int bb) {

    int c = bb - a;
    return c;
}

int main() {
    return b(1, 2);
}
