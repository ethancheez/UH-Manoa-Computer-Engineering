#include <stdio.h>
#include "maxmin.h"

int main() {

    int flag;
    float n1, n2;

    printf("Enter a pair of floats (CTRL+D to exit): ");
    flag = scanf("%f %f", &n1, &n2);

    while(flag != EOF) {
        printf("The larger of the two values is: %.2f\n", max(n1,n2));
        printf("The smaller of the two values is: %.2f\n", min(n1,n2));

        printf("Enter a pair of floats (CTRL+D to exit): ");
        flag = scanf("%f %f", &n1, &n2);
    }

}