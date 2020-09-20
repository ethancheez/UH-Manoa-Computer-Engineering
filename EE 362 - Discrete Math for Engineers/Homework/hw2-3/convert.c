#include <stdlib.h>
#include <stdio.h>

#define MAXLENGTH  100
#define DECIMALNUM 26

int bin2dec(char s[]) {
    int num = 0;
    int length = 0;
    int multiplier = 1;

    for(length; s[length] >= '0' && s[length] <= '1'; length++);

    for (int i = length-1; i >= 0; i--) {
        int bit = (int) (s[i]-'0');  /* bit = ith bit */
        bit = bit & 1;
        num += bit * multiplier;
        multiplier *= 2;
    }
    return num;
}

char* dec2bin(int n) {
    char * s = (char *) malloc(sizeof(char)*MAXLENGTH);

    int k=0;
    for (int q=n; q>0; q=q/2) {
        s[k] = ((char) q%2 ) + '0';
        k++;
    }
    s[k]='\0';

    char * bin = (char *) malloc(k);
    for(int i = 0; i < k; i++) {
        bin[i] = s[k-1-i];
    }

    free(s);
    return bin;
}

int main(void) {
    char a[10] = "100110";
    char* s=dec2bin(DECIMALNUM);
    printf("Decimal %d to binary %s\n",DECIMALNUM,s);
    free(s);
    printf("Binary %s to decimal %d\n",a,bin2dec(a));
}
