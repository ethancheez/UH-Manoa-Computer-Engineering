#include <stdio.h>
#include "julian.h"
#include "leap.h"

int main() {

    int startD, startM, startY;
    int endD, endM, endY;

    int datesDiff;

    printf("Enter a start date (dd mm yy) (EOF to quit): ");

    while( scanf("%d %d %d", &startD, &startM, &startY) != EOF ) {
        datesDiff = 0;

        printf("Enter a end date (dd mm yy) (EOF to quit): ");
        if( scanf("%d %d %d", &endD, &endM, &endY) == EOF ) break;

        if(startY > endY) {
            int temp = startD;
            startD = endD;
            endD = temp;

            temp = startM;
            startM = endM;
            endM = temp;

            temp = startY;
            startY = endY;
            endY = temp;
        }

        for(int i_year = startY; i_year < endY; i_year++) {
            if(is_leap(i_year)) {
                datesDiff += 366;
            } else {
                datesDiff += 365;
            }
        }
        datesDiff -= julian_date(startD, startM, startY);
        datesDiff += julian_date(endD, endM, endY);


        printf("\tFrom\t%2d %2d %2d \n\tTo\t%2d %2d %2d \n\t\t There are %d days \n", startD, startM, startY, endD, endM, endY, datesDiff);

        printf("Enter a start date (dd mm yy) (EOF to quit): ");
    }

    printf("\n");
}
