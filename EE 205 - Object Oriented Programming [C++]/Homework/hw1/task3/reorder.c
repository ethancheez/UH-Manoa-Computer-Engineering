#include <stdio.h>
#include "swap.h"

void reorder(float *a, float *b, float *c) {
	swap_big(c, a);
	swap_big(b, a);
	swap_big(c, b);
}
