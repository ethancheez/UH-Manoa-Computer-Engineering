// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

#define MAXLENGTH 100  /* Max length of a string */

int one_away(char str1[], char str2[]);
int str_length(char str[], int max_length);

char str[] = "pale";
char strA[] = "ple";
char strB[] = "pales";
char strC[] = "bale";
char strD[] = "bake";


void main() 
{
printf("'%s' and '%s' have result %d\n", str, strA, one_away(str, strA));
printf("'%s' and '%s' have result %d\n", str, strB, one_away(str, strB));
printf("'%s' and '%s' have result %d\n", str, strC, one_away(str, strC));
printf("'%s' and '%s' have result %d\n", str, strD, one_away(str, strD));
}


int one_away(char str1[], char str2[])
{
    int len1 = str_length(str1, MAXLENGTH);
    int len2 = str_length(str2, MAXLENGTH);
    int difference = len1 - len2;

    if(difference > 1 || difference < -1)
        return 0;

    // Find longest string length
    int max;
    (len1 > len2) ? (max = len1) : (max = len2);

    int numEdits = 0;
    for(int i = 0, j = 0; i < max || j < max; i++, j++) {
        if(str1[i] != str2[j]) {
            numEdits++;
            if(numEdits > 1) //More than 1 edit
                return 0;
            if(str1[i+1] == str2[j]) //Check right index of str1
                i++;
            else if(str1[i] == str2[j+1]) //Check right index of str2
                j++;
        }
    }
    
    return 1;
}



int str_length(char str[], int max_length)
{
int length;
for (length = 0; (str[length] != '\0') && (length < max_length); length++); 
return length;
}