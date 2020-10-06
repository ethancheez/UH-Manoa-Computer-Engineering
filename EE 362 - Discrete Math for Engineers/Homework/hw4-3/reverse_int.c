#include <stdlib.h>
#include <stdio.h>

int reverse_int(int n) {
    int newInt = 0;

    while(n != 0) {
        int digit = n % 10;
        newInt = newInt * 10 + digit;
        n /= 10;
    }

    return newInt;
}

int main() {
    int m = 456;
    printf("n = %d, reverse = %d\n", m, reverse_int(m));
    m = -456;
    printf("n = %d, reverse = %d\n", m, reverse_int(m));
    m = 3400;
    printf("n = %d, reverse = %d\n", m, reverse_int(m));

}


