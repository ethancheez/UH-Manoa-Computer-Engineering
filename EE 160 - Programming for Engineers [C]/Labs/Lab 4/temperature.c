#include <stdio.h>

float tocelsius(float f) {
    return ( (f - 32) * 5/9 );
}

int main() {

    float f, c;

    while(1) {
        printf("Enter a temperature in degrees Fahrenheit: ");
        scanf("%f", &f);

        if(f <= -500) {
            printf("Invalid Temperature \n");
            break;
        }

        c = tocelsius(f);

        printf("Degrees in Celsius: %.2f \n", c);
    }
    

}
