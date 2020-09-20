#include "table.h"

int largerElements(double a[], int num, double target) {
	int count = 0;
	for(int i = 0; i < num; i++) {
		if( a[i] > target ) {
			count++;
		}
	}
	return count;
}
