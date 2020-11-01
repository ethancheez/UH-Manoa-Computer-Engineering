#include "util.h"

long double factorial(int n) {
    long double result = 1;

    for(int i = n; i > 0; i--)
        result *= i;

    return result;
}

int close_enough(long double a, long double b) {

    long double difference = a - b;

    if(difference < 0)
        difference *= -1;

    if( difference < 0.00005 )
        return TRUE;

    return FALSE;
}