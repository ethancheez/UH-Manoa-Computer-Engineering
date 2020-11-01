#include <stdio.h>
#include "util.h"
#include "exponent.h"
#include "trig.h"

#define PI 3.141592653589793238462643

int main() {

    float original, angle;

    printf("Enter an angle in radians:  ");

    while( scanf("%f", &original) != EOF ) {

        angle = original;

        while(angle >= 2*PI)
            angle -= 2*PI;
        while(angle <= -2*PI)
            angle += 2*PI;

        printf("cos(%f) = %Lf \n", original, cosine(angle));

        printf("Enter an angle in radians:  ");
    }

    printf("\n");
}