#include <stdio.h>
#include "table.h"

void tablePrint(double a[], int num)
{
  int i;

  for (i = 0; i < num; i++)
    printf("%f\n", a[i]);
}
