// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

#define RANGE 5
#define THRESHOLD 30

/* Returns 1 if can win, and 0 otherwise */
/* k = differnce between sum and threshold */
int canwin(int memo[], int k) {

    if(k < 0)
        return 0;

    if(memo[k] != -1)
        return memo[k];

    if( (k % (RANGE + 1)) == 0 )
        memo[k] = 0;
    else
        memo[k] = 1;

    return canwin(memo, k-1);

}

int main() {
    int memo[THRESHOLD+1];  /* Create and initialize memo */
    for (int i=0; i<=THRESHOLD; i++) 
        memo[i]=-1;

    printf("Threshold=%d\n",THRESHOLD);

    int result = canwin(memo, THRESHOLD);
    
    for (int i=1; i<=THRESHOLD; i++) {
        printf("Sum=%3d ",THRESHOLD-i);
        if (memo[i]==1) 
            printf(" Win\n");
        else if (memo[i]==0) 
            printf(" Lose\n");
        else 
            printf(" Don't know\n");
    }
}

