#include <stdio.h>
#include "menu.h"
//#include "display.h"
#define FLUSH while(getchar() != '\n');

void menu(char *difficulty){
    int system(char *s);    //For system("cat <file>") commands
    char choice;

    // Print title, prompt for a choice
    system("cat title1");
    printf("Select choice: ");
    choice = getchar();
    FLUSH

    while(choice != EOF){ 
        
        system("clear");
        //if 1-3, display respective file
        if(choice == '1') {
            system("cat move");
        } 
        else if(choice == '2') {
            system("cat flags");
        }
        else if(choice == '3') {
            system("cat points");
        }
        //if 4, prompt difficulty level
        else if(choice == '4'){
            system("cat level");
            printf("Select level: ");

            //scan difficulty level
            *difficulty = getchar();
            FLUSH
            break;
        } else {
            system("cat title1");   //display title1 (reset)
        }

        //Prompt new choice
        printf("Select choice: ");
        choice = getchar();
        FLUSH
        }
}