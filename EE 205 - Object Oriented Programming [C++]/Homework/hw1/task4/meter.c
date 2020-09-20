#include <stdio.h>
#include "meter.h"
#include "water.h"

float compute_usage(int num, int *vals, int use[], int *hi_idx) {

    float sum = 0;
    *hi_idx = 0;

    for(int i = 0; i < num-1; i++) {
        use[i] = *(vals+i+1) - *(vals+i);
        if(use[i] > use[*hi_idx]) {
            *hi_idx = i;
        }
        sum += use[i];
    }

    return sum / (num-1);

}