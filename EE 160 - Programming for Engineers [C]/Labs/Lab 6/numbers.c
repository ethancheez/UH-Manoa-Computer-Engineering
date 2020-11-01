//Problem 4 in section 2.9

#include <stdio.h>

#define DEBUG

int main() {

    int pos=0, neg=0, even=0, odd=0, pos_even=0, neg_odd=0, num=0;
    int sum_pos=0, sum_neg=0, sum_even=0, sum_odd=0, sum_pos_even=0, sum_neg_odd=0, sum_num=0;

    int input=0;

    printf("GIve me a freaking number: ");
    scanf("%d", &input);
    
    while( input != 0 ) {

        sum_num += input;
        num++;
        
        if(input > 0) {
            sum_pos += input;
            pos++;

            #ifdef DEBUG
                printf("DEBUG: %d is positive (count = %d, total = %d)\n", input, pos, sum_pos);
            #endif

            if(input % 2 == 0) {
                sum_even += input;
                even++;
                sum_pos_even += input;
                pos_even++;
                #ifdef DEBUG
                    printf("DEBUG: %d is even (count = %d, total = %d)\n", input, even, sum_even);
                    printf("DEBUG: %d is positive and even (count = %d, total = %d)\n", input, pos_even, sum_pos_even);
                #endif
            } else {
                sum_odd += input;
                odd++;
                #ifdef DEBUG
                    printf("DEBUG: %d is odd (count = %d, total = %d)\n", input, odd, sum_odd);
                #endif
            }

        } else {
            sum_neg += input;
            neg++;

            #ifdef DEBUG
                printf("DEBUG: %d is negative (count = %d, total = %d)\n", input, neg, sum_neg);
            #endif

            if(input % 2 != 0) {
                sum_odd += input;
                odd++;
                sum_neg_odd += input;
                neg_odd++;
                #ifdef DEBUG
                    printf("DEBUG: %d is odd (count = %d, total = %d)\n", input, odd, sum_odd);
                    printf("DEBUG: %d is negative and odd (count = %d, total = %d)\n", input, neg_odd, sum_neg_odd);
                #endif
            } else {
                sum_even += input;
                even++;
                #ifdef DEBUG
                    printf("DEBUG: %d is even (count = %d, total = %d)\n", input, even, sum_even);
                #endif
            }

        }

        #ifdef DEBUG
            printf("DEBUG: Total (count = %d, total = %d)\n", num, sum_num);
        #endif

        printf("GIve me a freaking number: ");
        scanf("%d", &input);
    }
    printf("There were %d positive numbers totaling %d\n", pos, sum_pos);
    printf("There were %d negative numbers totaling %d\n", neg, sum_neg);
    printf("There were %d even numbers totaling %d\n", even, sum_even);
    printf("There were %d odd numbers totaling %d\n", odd, sum_odd);
    printf("There were %d positive even numbers totaling %d\n", pos_even, sum_pos_even);
    printf("There were %d negative odd numbers totaling %d\n", neg_odd, sum_neg_odd);
    printf("There were %d total numbers totaling %d\n", num, sum_num);
}