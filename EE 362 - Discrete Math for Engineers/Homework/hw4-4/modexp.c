#include <stdlib.h>
#include <stdio.h>

#define N 37
#define E 999999999 //100000000
#define M 53

unsigned int modexp(unsigned int n, unsigned int e, unsigned int m) {
    
    /*
    unsigned int result = n;
    for (int i=0; i<e-1; i++) {
        result = (result*n)%m;
    }   
    */
    
    unsigned int result = 1;
    
    while(e > 0) {
        if(e & 1)
            result = (result*n) % m;
        n = (n * n) % m;
        e = e >> 1;
    }
    
    return result;
}

int main() {
    printf("%d^%d mod %d = %d\n", N, E, M, modexp(N,E,M));
}


