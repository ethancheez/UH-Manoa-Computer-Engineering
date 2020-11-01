#include <stdio.h>

int main() {
    int expected;
    int count;
    double sum;
    int value;

    int result;

    while ( (result = scanf("%d", &expected)) != EOF ) {

        if(result != 1) {
            printf("Error!  Can't read number of expected values.\n");
            return 0;
        }
            
        sum = 0;
        for (count = 0; count < expected; count++) {
            if( (result = scanf("%d", &value)) != 1 ) {
                printf("Error!  Can't read expected value #%d.\n", count);
                printf("Average of %d values is %.2f\n", count, count != 0 ? sum / count : 0.0);
                return 0;
            }
            else 
                sum += value;
        }
        
        printf("Average of %d values is %.2f\n", count, count != 0 ? sum / count : 0.0);
    }
    
}