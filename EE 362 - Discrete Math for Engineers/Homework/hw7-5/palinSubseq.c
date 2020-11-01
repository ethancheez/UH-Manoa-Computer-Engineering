// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

#define DIM 80 /* Dimension of 2D array */

int max(int a, int b) {
    if (a > b) return a;
        return b;
}

int palinSubseq(char s[], int first, int last, int (*memo)[DIM], int dim) {
    if (first>last) 
        return 0;
    else if (first==last) 
        memo[first][last]=1;
    else {
        int middle = 0;
        if (s[first]==s[last]) {
            middle = 2+palinSubseq(s,first+1,last-1,memo,dim);
        }
        int left = palinSubseq(s,first,last-1,memo,dim);
        int right = palinSubseq(s,first+1,last,memo,dim);
        memo[first][last] = max(middle,max(left,right));
    }   
    return memo[first][last];
}

void displayPalinSubseq(char s[], int first, int last, int (*memo)[DIM], int dim) {

    if( first > last )
        return;
    else if( first == last )
        printf("%c", s[first]);
    else if(s[first] == s[last] && memo[first][last] == 2 + memo[first+1][last-1]) {
        printf("%c", s[first]);
        displayPalinSubseq(s, first+1, last-1, memo, dim);
        printf("%c", s[last]);
    } else {
        if(memo[first][last] == memo[first+1][last])
            displayPalinSubseq(s, first+1, last, memo, dim);
        else
            displayPalinSubseq(s, first, last-1, memo, dim);
    }
        
    return;
}

int palinSubseqMain(char s[], int length) {
    int memo[DIM][DIM];

    for (int i=0; i<length; i++) {
        for (int j=0; j<length; j++) {
            memo[i][j] = -1;
        }
    }

    int result = palinSubseq(s, 0, length-1, memo, length);
    displayPalinSubseq(s,0,length-1,memo,length);
    printf("\n");
    return result;
}

int strLength(char s[]) {
    int k=0;
    for(; s[k]!='\0'; k++);
    return k;
}

int main() {
    char str1[] = "abcabcbcabaacba";
    char str2[] = "aaabbbaba";
    int result;
    int length;

    length = strLength(str1);
    printf("String = %s Length=%d\n",str1,length);
    printf("Longest palindrome: ");
    result = palinSubseqMain(str1, length);
    printf("Length of palindrome=%d\n",result,length);

    printf("\n");

    length = strLength(str2);
    printf("String = %s Length=%d\n",str2,length);
    printf("Longest palindrome: ");
    result = palinSubseqMain(str2, length);
    printf("Length of palindrome=%d\n",result,length);
}