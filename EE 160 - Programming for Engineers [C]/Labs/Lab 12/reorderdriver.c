#include <stdio.h>
#include "swap.h"

#define DEBUG


int main()
{
	float a, b, c;

	while( scanf("%f %f %f", &a, &b, &c) != EOF ) {
        printf("Before: a=%f  b=%f  c=%f\n", a, b, c);
		reorder(&a, &b, &c);
        printf("After: a=%f  b=%f  c=%f\n\n", a, b, c);
	}

}
