#include <stdio.h>
#define ANNUALLY -1
#define MONTHLY 2
#define DAILY 3

float calc_acc_amt(float acc_amount, float annual_interest, int years);

int main() {
    //declare variables
    float acc_amount, interest_rate;
    int flag, years, action;

    printf("Enter Initial Amount (EOF to exit): ");
    flag = scanf("%f", &acc_amount);

    // while loop
    while (flag != EOF){

        //user enters rate of interest
        printf("Enter Rate of Interest: ");
        scanf("%f", &interest_rate);

        printf("Enter number of years of compounding: ");
        scanf("%d", &years);

        //User enters mode
        while(1) {
            printf("Enter compounding Annual/Monthly/Daily [-1/2/3]: ");
            scanf("%d", &action);
            if(action == -1 || action == 2 || action == 3)
                break;
            printf("ERROR: Please enter input properly\n");
        }

        //Yearly compoound
        if (action == ANNUALLY){
            printf("Accumulated Value: $%.2f \n\n", calc_acc_amt(acc_amount, interest_rate, years));
        }
        //Monthly compounding
        else if (action == MONTHLY) {
            printf("Accumulated Value: $%.2f \n\n", calc_acc_amt(acc_amount, interest_rate/12, years*12));
        }
        //Daily compounding
        else if (action == DAILY) {
            printf("Accumulated Value: $%.2f \n\n", calc_acc_amt(acc_amount, interest_rate/365, years*365));
        }

        printf("Enter Initial Amount (EOF to exit): ");
        flag = scanf("%f", &acc_amount);

    }

}

float calc_acc_amt(float acc_amount, float annual_interest, int years) {
    for(int i = years; i > 0; i--) {
        acc_amount = acc_amount + acc_amount * annual_interest;
    }
    return acc_amount;
}
