#include <stdio.h>
#include <stdlib.h>

int plus(int x, int y) {
    return x + y;
}

void sumstore(int x, int y, int *dest) {
    int t = plus(x, y);
    *dest = t;
}

int main(int argc, char* argv[]) {
    long x = atoi(argv[1]);
    long y = atoi(argv[2]);
    long z;
    sumstore(x, y, &z);
    printf("%ld + %ld ---> %ld\n", x, y, z);
    return 0;
}