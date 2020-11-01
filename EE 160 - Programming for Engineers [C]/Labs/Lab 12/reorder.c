#include <stdio.h>
#include "swap.h"

void reorder(float *a, float *b, float *c) {
	swap_big(a, c);
	swap_big(a, b);
	swap_big(b, c);
}
