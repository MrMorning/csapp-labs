#include <stdio.h>
void show_bytes(void* ptr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%02hhx ", *((char*)ptr));
        ptr++;
    }
}
int howManyBits(int x) {
  int xx = x;
  int neg = !!(x & (1 << 31));
  x = neg ? (~x + 1) : x;
  int ret = 0;
  int mask = ~(~0 << 16);
  int test16 = !!((x & mask) ^ x); //if high 16 is all 0, then test16 = 0, otherwise test16 = 1
  ret += test16 << 4;
  x = test16 ? (x >> 16) : x;
  mask >>= 8;
  int test8 = !!((x & mask) ^ x); //if high 8 is all 0, then test8 = 0, otherwise test8 = 1
  ret += test8 << 3;
  x = test8 ? (x >> 8) : x;
  mask >>= 4;
  int test4 = !!((x & mask) ^ x); //if high 4 is all 0, then test4 = 0, otherwise test4 = 1
  ret += test4 << 2;
  x = test4 ? (x >> 4) : x;
  mask >>= 2;
  int test2 = !!((x & mask) ^ x); //if high 2 is all 0, then test2 = 0, otherwise test2 = 1
  ret += test2 << 1;
  x = test2 ? (x >> 2) : x;
  mask >>= 1;
  int test1 = !!((x & mask) ^ x); //if high 1 is all 0, then test1 = 0, otherwise test1 = 1
  ret += test1 << 0;
  x = test1 ? (x >> 1) : x;
  printf("ret = %d, neg = %d\n", ret, neg);
  printf("test = %d\n", !!((xx ^ (1 << ret))));
  int flag = (!neg | !!((xx ^ (1 << ret)))) & !!(xx);
  return ret + 1 + flag;
}


int main() {
    unsigned pr = howManyBits(-1);
    printf("%0x", pr);
    //show_bytes((void*)(&pr), sizeof(unsigned));
}
