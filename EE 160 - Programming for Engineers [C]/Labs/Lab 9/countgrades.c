#include <stdio.h>

#define DEBUG

int main() {
    int a, b, c, d, f, others;

    char input;

    a = b = c = d = f = others = 0;

    while ( (input = getchar()) != EOF ) {
        switch(input) {
            case 'a': 
            case 'A':
                a++;
                break;
            case 'b': 
            case 'B':
                b++;
                break;
            case 'c': 
            case 'C':
                c++;
                break;
            case 'd': 
            case 'D':
                d++;
                break;
            case 'f': 
            case 'F':
                f++;
                break;

            default: 
                if(input != '\n')
                    others++;  
        }
    }
    printf("Grade counts:\n");

    printf("  A's: %d\n", a);
    printf("  B's: %d\n", b);
    printf("  C's: %d\n", c);
    printf("  D's: %d\n", d);
    printf("  F's: %d\n", f);
    printf("  Other grades: %d\n", others);

}