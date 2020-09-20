#include <stdio.h>

int main() {

    int flag;
    float sum, input;

    /*  Initialize the sum  */
    sum = 0;

    /*  Get the first input  */
    printf("Enter an integer value: ");
    flag = scanf("%f", &input);

    /*  While there is more input  */
    while(flag != EOF) {
        /*  Accumulate the sum  */
        sum += input;

        /*  Get the next input  */
        printf("Enter an integer value: ");
        flag = scanf("%f", &input);
    }

    /*  Print the results  */
    printf("\nSum: %.2f\n", sum);

}
