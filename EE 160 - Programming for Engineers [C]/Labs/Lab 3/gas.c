#include <stdio.h>

int main() {

    float gallons, miles, fill_cost, cost_per_mile, miles_per_gal;

    printf("Number of gallons used: ");
    scanf("%f", &gallons);

    printf("Number of miles since last fill up: ");
    scanf("%f", &miles);

    fill_cost = gallons * 3.12;
    cost_per_mile = fill_cost / miles;
    miles_per_gal = miles / gallons;

    printf("Number of gallons:  %.2f \n", gallons);
    printf("Cost per gallon:    $3.12 \n");
    printf("Cost of fill-up:    $%.2f \n", fill_cost);
    printf("Cost per mile:      $%.2f \n", cost_per_mile);
    printf("Miles per gallon:   %.2f \n", miles_per_gal);

}
