#include <stdio.h>

int main() {

    int flag, numInputs;
    float sum, avg, weight, value, totalWeight;

    /*  Initialize  */
    totalWeight = 0;
    numInputs = 0;
    sum = 0;

    /*  Get the first inputs  */
    printf("Enter a weight/value pair: ");
    flag = scanf("%f %f", &weight, &value);

    /*  While there is more input  */
    while(flag != EOF) {
        /*  Accumulate the sum  */
        sum += (weight * value);
        numInputs++;
        totalWeight += weight;

        /*  Get the next inputs  */
        printf("Enter a weight/value pair: ");
        flag = scanf("%f %f", &weight, &value);
    }

    /*  Average  */
    avg = sum / totalWeight;

    /*  Print the results  */
    printf("\nThe weighted average of %d input values is %f \n", numInputs, avg);

}
