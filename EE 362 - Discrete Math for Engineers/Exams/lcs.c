// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

//used for debugging
//#define lenDEBUG
//#define displayDEBUG

#define DIM 80
#define EMPTY -1
#define DEC_STR1 1
#define DEC_STR2 2
#define DEC_BOTH 3

int max(int a, int b); /* Returns max(a,b) */
int strLength(char s[]); /* Returns the length of a char string */
int ** createMemo(int numRow, int numCol);
void destroyMemo(int ** memo, int numRow);


int lcsRec(char  str1[], char str2[] , int ** memoLength, int ** memoPath, int len1, int len2) {
    if(len1 == 0 || len2 == 0)
        return 0;

    if (memoLength[len1-1][len2-1]==EMPTY) {
         
        if(str1[len1-1] == str2[len2-1]){
	        memoLength[len1-1][len2-1] = 1 + lcsRec(str1, str2, memoLength, memoPath, len1-1, len2-1);
	        memoPath[len1-1][len2-1]=DEC_BOTH;

            #ifdef lenDEBUG
                printf("len1: %d \t len2: %d \t --- memoPath: %d \n", len1, len2, memoPath[len1-1][len2-1]);
            #endif
 
        } else {

            int dec1, dec2;
            memoLength[len1-1][len2-1] = max( (dec1 = lcsRec(str1, str2, memoLength, memoPath, len1-1, len2)), (dec2 = lcsRec(str1, str2, memoLength, memoPath, len1, len2-1)));

            //remember action in memoPath[][]
            if(dec1 >= dec2 && memoPath[len1-1][len2] == EMPTY)
                memoPath[len1-1][len2]=DEC_STR1;
            else if(memoPath[len1][len2-1] == EMPTY)
                memoPath[len1][len2-1]=DEC_STR2;

            #ifdef lenDEBUG
                printf("len1: %d \t len2: %d \t --- memoPath: %d \n", len1, len2, memoPath[len1-1][len2-1]);
            #endif
        }
    }	
    return memoLength[len1-1][len2-1];
}

/*  Note: the first LCS did not print the same as the example...
 *  but it is still a possible LCS given those two strings.
 */
void lcsDisplay(int ** memoPath, char str[], int len1, int len2) {
    
    if(len1 == 0 || len2 == 0)
        return;

    if(memoPath[len1-1][len2-1] == DEC_BOTH) {
        lcsDisplay(memoPath, str, len1-1, len2-1);
        printf("%c", str[len1-1]);
    } else if(memoPath[len1-1][len2] >= memoPath[len1][len2-1]) {
        lcsDisplay(memoPath, str, len1-1, len2);
    } else {
        lcsDisplay(memoPath, str, len1, len2-1);
    }
    
    
    #ifdef displayDEBUG //tried working it out using a for loop first
        for(int i = 0, j = 0; i < len1 && j < len2; ) {
            printf("memoPath[%d][%d] = %d \n", i, j, memoPath[i][j]);
            
            if(memoPath[i][j] == DEC_BOTH) {
                printf("%c", str[i]);
                i++;
                j++;
            }
            else if(memoPath[i+1][j] >= memoPath[i][j+1]) {
                i++;
            } else {
                j++;
            }
        }
    #endif
   
    return;
}

int lcs(char str1[], char str2[])
{
int len1 = strLength(str1);
int len2 = strLength(str2);

int ** memoLength = createMemo(len1,len2);
int ** memoPath = createMemo(len1,len2);
for (int i=0; i<=len1; i++) {
   for (int j=0; j<=len2; j++) {
      memoLength[i][j]=EMPTY;
      memoPath[i][j]=EMPTY;
   }
}

int result = lcsRec(str1, str2, memoLength, memoPath, len1, len2);
printf("LCS: ");
lcsDisplay(memoPath, str1, len1, len2);
printf("\n");

destroyMemo(memoPath,len1);
destroyMemo(memoLength,len1);
return result;
}


int main()
{
char str1[]="ABCAABCCABCCBA"; 
char str2[]="BABCCCBBACAA";

char str3[]="ABCBDAB";
char str4[]="BDCABA";

int length;

length = strLength(str1);
printf("String = %s Length=%d\n",str1,length);
length = strLength(str2);
printf("String = %s Length=%d\n",str2,length);
printf("LCS length = %d\n",lcs(str1,str2));
printf("\n");

length = strLength(str3);
printf("String = %s Length=%d\n",str3,length);
length = strLength(str4);
printf("String = %s Length=%d\n",str4,length);
printf("LCS length = %d\n",lcs(str3,str4));
}

int ** createMemo(int numRow, int numCol)
{
int ** memo = (int **) malloc(sizeof(int *)*(numRow+1));
for (int i=0; i<=numRow; i++) {
    memo[i] = (int *) malloc(sizeof(int)*(numCol+1));
}
return memo;
}

void destroyMemo(int ** memo, int numRow)
{
for (int i=0; i<numRow; i++) free(memo[i]);
}


int max(int a, int b)
{
if (a > b) return a;
return b;
}

int strLength(char s[])
{
int k=0;
for(; s[k]!='\0'; k++);
return k;
}
