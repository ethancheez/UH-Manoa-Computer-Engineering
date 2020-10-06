#include <stdio.h>

int round_to_int(float value);

int main() {
    float num;

    while(1) {
        printf("Enter a number to round (0 to exit): ");
        scanf("%f", &num);

        if(num == 0)
            break;

        printf("Rounded Number: %d \n", round_to_int(num));
    }
}

int round_to_int(float value) {
    return (int) (value + 0.5);
}
