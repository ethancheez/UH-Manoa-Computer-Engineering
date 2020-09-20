#include <stdio.h>

int main() {

    int flag, numInputs;
    float sum, avg, input;

    /*  Initialize the sum  */
    numInputs = 0;
    sum = 0;

    /*  Get the first input  */
    printf("Enter an integer value: ");
    flag = scanf("%f", &input);

    /*  While there is more input  */
    while(flag != EOF) {
        /*  Accumulate the sum  */
        sum += input;
        numInputs++;

        /*  Get the next input  */
        printf("Enter an integer value: ");
        flag = scanf("%f", &input);
    }

    /*  Average  */
    avg = sum / numInputs;

    /*  Print the results  */
    printf("\nThe average of %d input values is %f \n", numInputs, avg);

}
