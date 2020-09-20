#include <stdio.h>

float calc_acc_amt(float acc_amount, float annual_interest, int years);

int main() {

    float acc_amount, annual_interest;
    int num_years;

    while(1) {
        printf("Enter initial amount (0 to exit): ");
        scanf("%f", &acc_amount);
        if(acc_amount == 0)
            break;

        printf("Enter annual interest rate (in decimals): ");
        scanf("%f", &annual_interest);

        printf("Enter number of years of compounding: ");
        scanf("%d", &num_years);
        
        printf("Accumulated Value: $%.2f \n\n", calc_acc_amt(acc_amount, annual_interest, num_years));
    }

}

float calc_acc_amt(float acc_amount, float annual_interest, int years) {
    for(int i = years; i > 0; i--) {
        acc_amount = acc_amount + acc_amount * annual_interest;
    }
    return acc_amount;
}
