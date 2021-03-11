// Ethan Chee

#include <stdio.h>
#include <stdlib.h>

#define nINF -999999999

int maxSubArray(int a[], int left, int right)
{
    if(left == right)
        return a[left];

    int mid = (left+right)/2;
    int subLeft = maxSubArray(a, left, mid); //find max of left subarray
    int subRight = maxSubArray(a, mid+1, right); //find max of right subarray

    int sum = 0;
    //find max across midpoint
    int leftMax = nINF;
    for(int i = mid; i >= left; i--) {
        sum += a[i];
        if(sum > leftMax)
            leftMax = sum;
    }
    sum = 0;
    int rightMax = nINF;
    for(int i = mid+1; i <= right; i++) {
        sum += a[i];
        if(sum > rightMax)
            rightMax = sum;
    }

    //find max of subLeft, subRight, and leftMax+rightMax
    int max = subLeft;
    if(subRight > max)
        max = subRight;
    if(leftMax + rightMax > max)
        max = leftMax + rightMax;
    
    return max;
}

int main()
{
int a[9]={-2,1,-3,4,-1,2,1,-5,4};
printf("Max subarray of first array = %d\n", maxSubArray(a,0,8));
int b[12]={1,1,-3,4,-1,9,1,-5,4,2,-4,2};
printf("Max subarray of second array = %d\n", maxSubArray(b,0,11));
}