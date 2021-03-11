// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

/*
 * memo[k] is the length of the longest increasing subsequence 
 * that ends at k.
 */

int increase(int num[], int length)
{
    int * memo = (int *)malloc(length*sizeof(int));
    for (int i=0; i<length; i++) {
        memo[i]=1;
        for (int k=0; k<i; k++) {
            if (num[k] < num[i] && memo[i]<memo[k]+1) {
                memo[i]=memo[k]+1;
                
            }
        }
    }
    int result = 0;
    printf("Solution:");
    for (int i=0; i<length; i++) {
        if (memo[i] > result) {
            printf(" %d", num[i]);
            result = memo[i];
        }
    }
    printf("\n");
    free(memo);
    return result;
}

void displayArray(int num[], int length)
{
for (int i=0; i<length; i++) {
    printf(" %3d",num[i]);
}
printf("\n");
}


int main()
{
int num1[]={10,9,2,5,3,7,101,18};
int length1=8;
printf("Array: ");
displayArray(num1,length1);
printf("Length= %d\n",increase(num1,length1));

int num2[]={10,24,2,7,3,30,20,5,7,9,21,14,21,8,22};
int length2=15;
printf("Array: ");
displayArray(num2,length2);
printf("Length= %d\n",increase(num2,length2));
}
