#include <stdio.h>
#include "exponent.h"
#include "util.h"

//#define DEBUG

long double cosine(float x) {

    int n = 0;
    long double prev_result = 0;
    long double final_result = 0;

    while(1) {

        prev_result = final_result;

        final_result = prev_result + (pos_power(-1, n) * pos_power(x, 2*n) / factorial(2*n));

        #ifdef DEBUG
            printf("n = %d \t\t", n);
            printf("FACTORIAL: %.Lf \t\t\t", factorial(2*n));
            printf("CURRENT: %Lf \t\t", pos_power(-1, n) * pos_power(x, 2*n) / factorial(2*n));
            printf("FINAL: %Lf \n", final_result);
        #endif

        if(close_enough(prev_result, final_result))
            break;

        n++;
    }

    return final_result;
}