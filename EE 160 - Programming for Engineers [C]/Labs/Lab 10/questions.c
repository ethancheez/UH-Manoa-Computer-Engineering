#include <stdio.h>
#include "tfdef.h"

int yesOrNo(void);

int main() {
    printf("Don't you just love this class? ");
    if (yesOrNo())
        printf("YES!  We knew it.\n");
    else
        printf("NO?  Come on, you know you love this class.\n");
}

int yesOrNo(void) {
    int answer;                        /* holds input character */
    int c;

    while(TRUE) {
        /* process each input line */

        c = getchar();
        
        if ((answer = tolower(c)) == EOF)
            return FALSE;                  /* EOF is NO! */

        /* read characters until the end of the line */
        while(c != '\n' && c != EOF)
            c = getchar();

        /* return an appropriate value for Yes or No */
        if (answer == 'y')
            return TRUE;
        if (answer == 'n')
            return FALSE;

        /* error message if there's a problem */
        printf("Please answer with a YES or NO: ");
    }
}