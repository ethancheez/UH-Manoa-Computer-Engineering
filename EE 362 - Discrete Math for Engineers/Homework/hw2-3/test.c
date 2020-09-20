#include <stdlib.h>
#include <stdio.h>

#define MAXLENGTH  100
#define DECIMALNUM 26

int bin2dec(char s[])
{
int num=0;
for (int i=0; s[i]!='\0'; i++) {
    int bit= (int) (s[i]-'0');  /* bit = ith bit */
    bit = bit&1;
    num += bit;
}
return num;
}

char* dec2bin(int n)
{
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
    s = bin;

    return s;
}

int main(void)
{
char a[10] ="1000000001";
char* s=dec2bin(DECIMALNUM);
printf("Decimal %d to binary %s\n",DECIMALNUM,s);
free(s);
printf("Binary %s to decimal %d\n",a,bin2dec(a));
}
