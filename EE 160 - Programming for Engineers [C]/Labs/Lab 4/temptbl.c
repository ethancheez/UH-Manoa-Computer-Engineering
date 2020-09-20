#include <stdio.h>

float tocelsius(float f) {
    return ( (f - 32) * 5/9 );
}

int temptable(float start, float stop) {
    float c;
    int number_of_lines = 0;
    printf("===F===|===C===\n");
    if(start < stop) {
        for(float i = start; i <= stop; i+=5) {
            c = tocelsius(i);

            printf("%.2f  | %.2f  \n", i, c);
            number_of_lines++;
        }
    } else {
        for(float i = start; i >= stop; i-=5) {
            c = tocelsius(i);

           printf("%.2f  | %.2f  \n", i, c);
            number_of_lines++;
        }
    }
    
    return number_of_lines;
}

int main() {

    float start, stop;

    while(1) {
        printf("Enter a temperature to start in degrees Fahrenheit: ");
        scanf("%f", &start);
        printf("Enter a temperature to stop in degrees Fahrenheit: ");
        scanf("%f", &stop);

        if(start == stop)
            break;

        int number_of_lines = temptable(start, stop);
        printf("Computed %d temperatures\n", number_of_lines);
    }

}
