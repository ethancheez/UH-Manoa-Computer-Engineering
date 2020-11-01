/*      File : avg.c            *
 *      By   :                  *
 *      login:                  *
 *      team :                  *
 *      Date :                  */

/*
 * Compute average of its input values.
 */

#include <stdio.h>

int main() {
    int          next;               /* next input value */
    long         sum;                /* running total */
    unsigned int n;                  /* number of input values */
    int          result;             /* did we read another value? */
    double       avg;                /* average of input values */

    sum = n = 0;
    while( (result = scanf("%d", &next)) == 1 ) {
        sum += next;
        n++;
    }

    if (result != EOF)
        printf("Warning: bad input after reading %u values\n", n);
    
    printf("Average of %u values is %f.\n", n, (n == 0) ? 0.0 : (double) sum / n);
  
}