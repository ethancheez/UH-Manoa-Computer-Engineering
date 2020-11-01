#include <stdio.h>
#include "maxmin.h"

#define DEBUG

int main() {

    int flag;
    float input, highest, lowest;

    printf("Enter a freaking number: ");
    flag = scanf("%f", &input);

    highest = input;
    lowest = input;

    while(flag != EOF) {
        highest = max(highest, input);
        lowest = min(lowest, input);

        #ifdef DEBUG
            printf("== DEBUG == Current Highest: %.2f \t Current Lowest: %.2f\n", highest, lowest);
        #endif

        printf("Enter a freaking number: ");
        flag = scanf("%f", &input);
    }

    printf("\n\nHighest: %.2f \n", highest);
    printf("Lowest:  %.2f \n", lowest);
}