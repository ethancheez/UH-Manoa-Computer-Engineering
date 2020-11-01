#include <stdio.h>
#include "mygrader.h"

int main() {
    int score;
    char grade;

    while(scanf("%d", &score) == 1) {
        printf("%d: ", score);
        grade = assign_grade(score);
        if(grade == '?')
            printf("illegal score\n");
        else
            printf("%c\n", grade);
    }

}