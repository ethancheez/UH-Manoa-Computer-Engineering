#include <stdio.h>
#include "exponent.h"

int main() {

    float base, exponent;

    printf("Enter a base and exponenet: ");
    scanf("%f %f", &base, &exponent);

    printf("Result = %.2f \n", pos_power(base, exponent));

}