#include <stdio.h>

int round_to_int(float value);

int main() {
    int days;
    float excess;

    float jog_total_mb = 0, jog_cost = 0;
    float holo_total_mb = 0, holo_cost = 0;

    printf("\t Day \t Excess \n");

    while( scanf("%d %f", &days, &excess) != EOF ) {
        jog_total_mb += round_to_int(excess);
        holo_total_mb += excess;
        
        printf("\t %d \t %.2f \n", days, excess);
    }
    holo_total_mb = round_to_int(holo_total_mb);

    jog_cost = jog_total_mb * 0.05;
    holo_cost = holo_total_mb * 0.07;

    printf("Jog would charge you $%.2f for %.2f MB of excess data \n", jog_cost, jog_total_mb);
    printf("Holo-T would charge you $%.2f for %.2f MB of excess data \n", holo_cost, holo_total_mb);
}

int round_to_int(float value) {
    return (int) (value + 0.5);
}
