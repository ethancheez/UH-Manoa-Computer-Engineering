#include <stdio.h>
#include "leap.h"

int main() {
    int year;
    printf("Enter the year you want to check (0 to exit): ");
    scanf("%d",&year);
                
    while(year > 0){
        if(is_leap(year))
            printf("Year %d is a leap year\n",year);
        else{
            printf("Year %d is NOT a leap year\n",year);
        }
        printf("Enter the year you want to check (0 to exit): ");
        scanf("%d",&year);
    }

    printf("\n");
}
