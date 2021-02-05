/* Ethan Chee
 * 
 * Your task is to modify function rob_rec() to solve the Robber Problem
 * by implementing dynamic programming with memoization.  Your
 * algorithm should run in O(n) time where n is the length of the array.
 *
 * The main function calls function rob() four times with different
 * inputs, in particular the array money[ ] will be different each
 * time.  Recall, that money[k] is the amount that can be stolen
 * at house k.
 *
 * The function should return the maximum amount that can be stolen
 * This will be displayed as a Score.  The function should also 
 * indicate in the house[] array, which houses should be robbed, 
 * e.g., house[k] = 1 means house k should be robbed, and house[k] = 0
 * means it should not be robbed.
 *
 * Note that 
 *    - rob() calls function rob_rec().
 *    - array house[] is initialized to 0.  
 *    - main also calls check_houses() which checks if house[] is valid
 * 
 * You can modify rob(), rob_rec(), and introduce new functions that rob()
 * can call. Do not modify main().
 */


#include <stdlib.h>
#include <stdio.h>

#define HOUSE_SIZE 20

int rob(int* money, int* house, int numHouses);

/*  Utility functions */
void clear_houses(int * house, int length); /* Clears array house[] */
void check_houses(int * house, int * money, int length);  /* Checks if houses are valid */
void random_fill(int * money, int length); /* Randomly fill array */
void display_array(int* a, int length); 

void main()
{
int money1[4] = {1, 2, 3, 1};
int money2[5] = {2, 7, 9, 3, 1};
int money3[5] = {10, 7, 3, 9, 1};
int money4[HOUSE_SIZE];
random_fill(money4, HOUSE_SIZE); /* Fill money4[ ] */

int house[HOUSE_SIZE];

clear_houses(house,4);
printf("\nScore = %d\n", rob(money1,house,4));
check_houses(house, money1, 4);

clear_houses(house,5);
printf("\nScore = %d\n", rob(money2,house,5));
check_houses(house, money2, 5);

clear_houses(house,5);
printf("\nScore = %d\n", rob(money3,house,5));
check_houses(house, money3, 5);

clear_houses(house,HOUSE_SIZE);
printf("\nScore = %d\n", rob(money4,house,HOUSE_SIZE));
check_houses(house, money4, HOUSE_SIZE);
}

int rob_rec(int* money, int* house, int* memo, int numHouses, int index) {

    // Stop recursion
    if(index < 0)
        return 0;
    
    //printf("Index: %d \t Memo: %d \n", index, memo[index]); //DEBUGGING
    
    // Memoization
    if(memo[index] != -1)
        return memo[index];


    if(numHouses == 0)  //if there are no houses... well we can't rob anything :(
        return 0;
    else if(numHouses == 1) {   //if there is only one house... well just rob that one
        house[0] = 1;
        return money[0];
    }

    /*  Possible combination of houses to rob (two or more houses)
     * 
     *  1 0 1 0
     *  1 0 0 1
     *  0 1 0 1
     *  0 0 1 0
     */

    int score = 0;

    // 1 0 1 (start robbing at first house)
    int option1 = money[index] + rob_rec(money, house, memo, numHouses, index-2);

    // 0 1 0 (start robbing at second house)
    int option2 = rob_rec(money, house, memo, numHouses, index-1);

    // Pick, which option is better?
    if(option1 > option2)
        score = option1;
    else 
        score = option2;


    /*  If: 0 0 __
     *  Then either:
     *      0 1 __ (rob 2nd house because it is better than robbing third house)
     *      0 0 __ (don't do anything because robbing 2nd house is not the best option, proceed to next if statement)
     */
    if(house[index-2] == 0 && house[index-1] == 0 && money[index-1] > money[index])
        house[index-1] = 1;
    
    /*  If: 0 0 0 __
     *  Then:
     *      0 1 0 __
     */
    else if(house[index-3] == 0 && house[index-2] == 0 && house[index-1] == 0) 
        house[index-2] = 1;
    

    /*  If last index and if the house before was not robbed,
     *  Then rob last house
     */
    if(index == numHouses-1 && house[index-1] == 0)
        house[index] = 1;
    

    memo[index] = score;
    //printf("Current Score at Index %d: %d\n", index, score);  //DEBUGGING

    return score;
    
}

int rob(int* money, int* house, int numHouses) {
    int memo[HOUSE_SIZE+1];  /* Create and initialize memo */

    for (int k=0; k<=numHouses; k++) {
        memo[k] = -1;
    }
    return rob_rec(money, house, memo, numHouses, numHouses-1);
}


/* Utility functions */

void display_array(int* a, int length) 
{
for (int k=0; k<length; k++) {
    printf("%3d",a[k]);
}
printf("\n");
}

void random_fill(int * money, int length)
{
int state = 11;
for (int k=0; k<length; k++) {
    state = (53*state + 71)%97;
    money[k] = state;
}
}

void check_houses(int * house, int * money, int length) 
{
for (int k=0; k+1 < length; k++) {
    if (house[k] == 1 && house[k+1] == 1) {
	printf("Houses %d and %d are being robbed\n", k, k+1);
    }
    else if (house[k] !=0 && house[k] != 1) {
	printf("House %k is invalid\n", house[k]);
    }
}
int check_score=0;

for (int k=0; k<length; k++) {
    if (house[k] == 1) check_score += money[k];
}

printf("Check to verify solution:\n");
printf("   Score = %d\n", check_score);
printf("   Money = ");
display_array(money,length);
printf("   House = ");
display_array(house,length);
return;
}

void clear_houses(int * house, int length)
{
for (int i=0; i<length; i++) {
    house[i] = 0;
}
}
