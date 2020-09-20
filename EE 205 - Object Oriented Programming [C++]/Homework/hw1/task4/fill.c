#include <stdio.h>
#include "table.h"

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
