#include <stdio.h>
 
int main() {  
        float velocity, distance, time;
 
        /*  set the time  */
        printf("Input a time: ");
        scanf("%f", &time);
 
        /*  compute the velocity */
        velocity = 32.0 * time;
 
        /*  compute the distance  */
        distance = 32 * time * time / 2;
 
        /*  print the result  */
        printf("An object falling %4.2f feet in %4.2f seconds ", distance, time);
        printf("is traveling %4.2f ft/sec\n", velocity);
}
