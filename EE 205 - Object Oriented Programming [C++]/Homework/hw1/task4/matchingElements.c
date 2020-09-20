#include <stdio.h>
#include "table.h"

int tableMatchingElements(double a[], int num, double target)
{
	int match = 0;
	for( int i = 0; i < num; i++ ) {
		if( a[i] == target ) {
			match++;
		}
	}
  	return match;        /* number of values equal to the target */
}
