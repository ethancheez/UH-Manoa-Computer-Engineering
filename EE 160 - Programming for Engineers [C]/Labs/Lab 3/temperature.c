#include <stdio.h>

int main() {

    float f, c;

    printf("Enter a temperature in degrees Fahrenheit: ");
    scanf("%f", &f);

    c = (f - 32) * 5/9;

    printf("Degrees in Celsius: %.2f \n", c);

}
