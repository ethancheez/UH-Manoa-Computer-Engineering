// Ethan Chee

#include <stdlib.h>
#include <stdio.h>

#define NUM_OF_HANDS    4
#define CARDS_PER_HAND  5
#define SIZE            52

int random367(int m, int n)
{
return m + (int) (drand48()*((double) (n-m+1)));
}

void main()
{
    short int randState[3];  /* State of the pseudo random number gen */
    for (int i=0; i<3; i++) {
        randState[i]=i;
    }
    seed48(randState);

    int arr[SIZE];
    int counter = 1;

    for(int i = 0; i < SIZE; i++) {
        arr[i] = i;
    }
    for(int i = 0; i < SIZE; i++) {
        int m = random367(i, SIZE);

        //printf("SWAPPING: %d[%d] and %d[%d]\n", i, arr[i], m-1, arr[m-1]);    //debugging
        int temp = arr[m-1];
        arr[m-1] = arr[i];
        arr[i] = temp;
    }

    for(int i = 0; i < NUM_OF_HANDS * CARDS_PER_HAND; i++) {

        if(counter == 1)
            printf("\nPoker hand %d: %d", 1 + (i+1)/5, arr[i]);
        else
            printf(", %d", arr[i]);
            
        counter++;

        if(counter > CARDS_PER_HAND)
            counter = 1;
    }
    printf("\n");
}
