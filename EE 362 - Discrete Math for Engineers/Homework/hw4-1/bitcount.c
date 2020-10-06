#include <stdlib.h>
#include <stdio.h>

/* Brute force method.  At most 32 loops */
int bitcount1(unsigned int n) {
    int count=0;
    for (unsigned int value=n; value!=0; value=value>>1) {
        count+=value&1;
    }   
    return count;
}

/* Number of loops equals number of 1s in n*/
int bitcount2(unsigned int n) {
    int count=0;
    for (unsigned leftOver=n; leftOver!=0; leftOver=leftOver&(leftOver-1)){
        count++;
    }
    return count;		
}

int bitcount3(unsigned int n) {
    int table[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
    int count=0;
    for (unsigned int leftOver=n; leftOver!=0; leftOver=leftOver>>4){
        count+=table[leftOver & 0xf];
    }
    return count;
}

int bitcount4(unsigned int n) {
    /* Change these masks */
    unsigned int mask1 = 0x55555555; // Every bit alternates between 0 and 1
    unsigned int mask2 = 0x33333333; // Every 2-bits alternates between 00 and 11
    unsigned int mask3 = 0x0f0f0f0f; // Every 4-bits alternates between 0000 and 1111
    unsigned int mask4 = 0x00ff00ff; // Etc.
    unsigned int mask5 = 0x0000ffff;

    unsigned int m = n;

    //printf("DEBUG 1: %x \t %d \n", m, m);
    m = (mask1 & m) + (mask1 & (m >> 1));
    //printf("DEBUG 2: %x \t %d \n", m, m);
    m = (mask2 & m) + (mask2 & (m >> 2));
    //printf("DEBUG 3: %x \t %d \n", m, m);
    m = (mask3 & m) + (mask3 & (m >> 4));
    //printf("DEBUG 4: %x \t %d \n", m, m);
    m = (mask4 & m) + (mask4 & (m >> 8));
    //printf("DEBUG 5: %x \t %d \n", m, m);
    m = (mask5 & m) + (mask5 & (m >> 16));
    //printf("DEBUG 6: %x \t %d \n", m, m);
    return m;
}

int main() {
    int k = 0xfff3055f; //0xfff3055f
    printf("bitcount1(%x): %d\n",k,bitcount1(k));
    printf("bitcount2(%x): %d\n",k,bitcount2(k));
    printf("bitcount3(%x): %d\n",k,bitcount3(k));
    printf("bitcount4(%x): %d\n",k,bitcount4(k));
}

