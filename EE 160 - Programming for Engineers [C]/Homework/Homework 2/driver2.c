#include <stdio.h>
#include "days.h"

int main(){
    int month,year,day;
    
    printf("Please input a month(1-12) and year (CTRL+D to exit): ");
    int flag =scanf("%d %d",&month,&year);
    
    while(flag != EOF){
        printf("%d-%d has %d days\n\n",month,year,days_in_month(month,year));

        printf("Please input a month(1-12) and year (CTRL+D to exit): ");
        flag = scanf("%d %d",&month,&year);
    }

    printf("\n");
}
