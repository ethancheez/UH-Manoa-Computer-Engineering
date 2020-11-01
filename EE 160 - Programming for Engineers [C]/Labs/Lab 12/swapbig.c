#include <stdio.h>
#include "swap.h"

void swap_big(float *a, float *b) {
	if( *b < *a ) {
		swap(a, b);
	}
}
