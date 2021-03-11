// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

int subseq(int num[], int length, int (*memo)[length+1], int index, int prev);

int increase(int num[], int length)
{
    int memo[length][length+1];

    for(int i = 0; i < length; i++)
        for(int j = 0; j < length+1; j++) 
            memo[i][j] = -1;
        
    return subseq(num, length, memo, 0, -1);
}

void displayArray(int num[], int length)
{
for (int i=0; i<length; i++) {
    printf(" %3d",num[i]);
}
printf("\n");
}

int subseq(int num[], int length, int (*memo)[length+1], int index, int prev) {
    if(index == length)
        return 0;
    if(memo[index][prev+1] != -1)
        return memo[index][prev+1];

    int result1 = 0, result2;

    if(prev == -1 || num[index] > num[prev])
        result1 = 1 + subseq(num, length, memo, index+1, index);
    result2 = subseq(num, length, memo, index+1, prev);

    if(result1 >= result2) 
        memo[index][prev+1] = result1;
    else
        memo[index][prev+1] = result2;
    
    return memo[index][prev+1];
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
