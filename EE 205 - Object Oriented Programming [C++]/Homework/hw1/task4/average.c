#include <stdio.h>
#include "table.h"

double tableAverage(double a[], int num)
{
	double sum;
	for(int i = 0; i < num; i++) {
		sum += a[i];
	}
  	return sum/num;      
}
