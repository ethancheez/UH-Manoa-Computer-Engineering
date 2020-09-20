#include <stdio.h>
#include "swap.h"

void swap_big(float *a, float *b) {
	if( *a <= *b ) {
		swap(a, b);
	}
}
