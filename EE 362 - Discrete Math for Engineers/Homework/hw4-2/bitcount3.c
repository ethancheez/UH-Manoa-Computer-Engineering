#include <stdio.h>

int main() {

    long int n = 0xffffffffffffffff;
    
    unsigned long int tmp = n - ((n >> 1) & 0x7777777777777777) - ((n >> 2) & 0x3333333333333333) - ((n >> 3) & 0x1111111111111111);
    printf("Bits: %d\n", ((tmp + (tmp >> 4)) & 0x0f0f0f0f0f0f0f0f) % 255);
    
}
