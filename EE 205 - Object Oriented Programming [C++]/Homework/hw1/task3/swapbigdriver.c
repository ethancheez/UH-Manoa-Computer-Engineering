#include <stdio.h>
#include "swap.h"

#define DEBUG


int main()
{
	float a, b;

	while( scanf("%f %f", &a, &b) != EOF ) {
		printf("Before: a=%f  b=%f\n", a, b);
		swap_big(&a, &b);
		printf("After: a=%f  b=%f\n\n", a, b);
	}

}
