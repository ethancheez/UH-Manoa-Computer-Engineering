#include <stdio.h>
#include "julian.h"

int main() {

    int day, month, year;

    printf("Enter the Day, Month, and Year to find Julian Date (EOF to exit): ");

    while( scanf("%d %d %d", &day, &month, &year) != EOF ) {
        printf("Julian Date: %d \n", julian_date(day, month, year));
        printf("Enter the Day, Month, and Year to find Julian Date (EOF to exit): ");
    }

    printf("\n");
}
