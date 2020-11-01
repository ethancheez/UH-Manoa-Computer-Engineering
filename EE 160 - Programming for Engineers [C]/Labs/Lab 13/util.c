#include <stdio.h>
#include "util.h"

int tableFill(double a[], int max)
{
  double next;              /* next input value */
  int r;                    /* return from trying to read values */
  int cnt = 0;              /* count of values read */

  while ((r = scanf("%lf", &next)) != EOF)
  {
    if (r != 1)     /* bad return from scanf */
    {
      printf("Error in the input after reading %d values.\n",
        cnt);
      break; 
    }
    if (cnt == max)     /* no room to store this value */
    {
      printf("Array full after reading %d values.\n", cnt);
      break;
    }
    a[cnt++] = next;  /* save element in array */
  }
  return cnt;
}

void tablePrint(double a[], int num) 
{              
  int i;

  for (i = 0; i < num; i++)
    printf("%f\n", a[i]);
}

double tableAverage(double a[], int num)
{
    double sum;
	for(int i = 0; i < num; i++) {
		sum += a[i];
	}
  	return sum/num;    
}

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


void printLarger(double a[], int num, double target) {
	for( int i = 0; i < num; i++ ) {
		if( a[i] > target ) {
			printf("%f\n", a[i]);
		}
	}
}

void printSmaller(double a[], int num, double target) {
	for(int i = 0; i < num; i++) {
		if( a[i] < target ) {
			printf("%f\n", a[i]);
		}
	}
}

int largerElements(double a[], int num, double target) {
	int count = 0;
	for(int i = 0; i < num; i++) {
		if( a[i] > target ) {
			count++;
		}
	}
	return count;
}

int smallerElements(double a[], int num, double target) {
        int count = 0;
        for(int i = 0; i < num; i++) {
                if( a[i] < target ) {
                        count++;
                }
        }
        return count;
}