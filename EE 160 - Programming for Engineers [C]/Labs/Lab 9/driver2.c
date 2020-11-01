#include <stdio.h>
#include "mygrader2.h"

int main() {
    int score, a, b, c, d;
    char grade;

    int passing=0, failing=0, illegal=0;

    scanf("%d %d %d %d", &a, &b, &c, &d);
    if( is_valid(a, b, c, d) == 0 ) {
        printf("%d %d %d %d\n", a, b, c, d);
        printf("invalid grading scale\n");
        return 0;
    }

    while(scanf("%d", &score) == 1) {
        printf("%d: ", score);
        grade = assign_grade(score, a, b, c, d);

        if(grade == '?') {
            illegal++;
            printf("illegal score\n");
        } else {
            if(grade >= 'A' && grade <= 'C')
                passing++;
            else
                failing++;

            printf("%c\n", grade);
        } 
    }

    printf("Passing Scores: %d\n", passing);
    printf("Failing Scores: %d\n", failing);
    printf("Illegal Scores: %d\n", illegal);

}