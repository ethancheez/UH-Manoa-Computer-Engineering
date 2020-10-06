#include <stdlib.h>
#include <stdio.h>

#define P 53
#define Q 47
#define MESSAGE 1234

/* modexp returns (n^e)%m */
unsigned int modexp(unsigned n, unsigned int e, unsigned int m) {
    unsigned int result = 1;
    unsigned int t = n;
    for (unsigned int k=e; k!=0; k=k>>1) {
        if (k&1 ==1) {
	        result = (result*t)%m;
        }
        t = (t*t)%m;
    }
    return result;
}

/* neg2posMod returns a positive version of n mod m */
unsigned int neg2posMod(int n, unsigned int m) {
    unsigned int result;
    if (n>=0) {
        result = n%m;
    } else {
        unsigned int temp = -n;
        result = m-(temp%m);
    }
    return result;
}

/* Make this function work */
unsigned int extEuclidean(unsigned int phi, unsigned int e) {
    unsigned int s = 1, prevs = 0;   //e * s
    unsigned int t = 0, prevt = 1;   //phi * t

    while (e != 0) {
        unsigned int temp = s;
        s = prevs - phi / e * s;
        prevs = temp;

        temp = t;
        t = prevt - phi / e * t;
        prevt = temp;

        temp = phi;
        phi = e;
        e = temp % e;
    }

    return prevs;   //return s
}


int main() {
    unsigned int phi = (P-1)*(Q-1);
    unsigned int e = 41*43;
    unsigned int n = P*Q;

    printf("Parameters:  P=%d, Q=%d, n=%d, phi=%d\n",P,Q,n,phi);

    unsigned int s = extEuclidean(phi,e);
    unsigned int d = neg2posMod(s,phi);

    printf("Verify e and d are inverses:  e=%d, d=%d, phi=%d, (e*d) mod phi=%d\n",e,d,phi,(e*d)%phi);

    unsigned int c = modexp(MESSAGE,e,n);
    unsigned int y = modexp(c,d,n);
    printf("Message=%d, Encrypted=%d, Decrypted=%d\n",MESSAGE,c,y);		
}
