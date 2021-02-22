#include <stdio.h>
int main() {
    int x = 1 << 31;
    printf("x=%d,\nx>>1=%d", x, x >> 33);
}