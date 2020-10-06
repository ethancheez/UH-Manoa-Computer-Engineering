#include <stdio.h>

int main() {
    //For y = mx + b
    float m = 0, b = 0;
    
    //Needed to calculate m and b
    int n = 0;
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;

    //Start and Stop
    float begin, end;

    //File input
    float x = 0, y = 0;

    //Begin Scanning File
    int flag = scanf("%f %f", &x, &y);
    begin = x;

    printf("p = [ %.2f", y);

    while(flag != EOF) {
        sum_x += x;
        sum_y += y;
        sum_xy += x * y;
        sum_x2 += x * x;
        n++;

        end = x;
        if( scanf("%f %f", &x, &y) == EOF ) break;

        printf(", %.2f", y);
    }
    printf(" ]; \n");

    //Calculate m and b
    m = ( n*sum_xy - sum_y*sum_x ) / ( n*sum_x2 - sum_x*sum_x );
    b = ( sum_y - m*sum_x ) / n;

    //Print outputs
    printf("x = linspace ( %.2f, %.2f, %d );\n", begin, end, n);
    printf("y = %.2f * x + %.2f;\n", m, b);
    printf("plot(x, y, p, 'go')\n");
    printf("text(0.5, 100, 'y = %.2f * x + %.2f');\n", m, b);
}
