#include <stdio.h>
#include "table.h"

void printSmaller(double a[], int num, double target) {
	for(int i = 0; i < num; i++) {
		if( a[i] < target ) {
			printf("%f\n", a[i]);
		}
	}
}
