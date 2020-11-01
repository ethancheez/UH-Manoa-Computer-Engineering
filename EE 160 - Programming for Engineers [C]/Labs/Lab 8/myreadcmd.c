/*	THIS FILE WAS MADE BY COLIN LAMBERT AND HIS GROUP
	FULL CREDIT GOES TO HIM AND HIS GROUP
 */

#include <stdio.h>
#define TRUE 1
#define FALSE 0

int skipBlanks(void);
int skipOverRestOfCommand(void);

int main() {

    int cmd;
    int repeat=FALSE;
    
    //  get the first character
    cmd = skipBlanks();      

    while (cmd != EOF) {
		//  Does not print duplicate error message for newline following a semicolon
		if(cmd==';')
	    	repeat=TRUE;	
	
		//  Prints the command if there is an upper or lower case letter
		if( (cmd >= 'a' && cmd <= 'z') || (cmd >= 'A' && cmd <= 'Z') ) {
        	printf("The command is: %c\n", cmd);	
	    	skipOverRestOfCommand();
		} else {	

    		//  prints error message when there are only spaces or tabs 
	    	//  between semicolons or newlines	
	    	if(cmd==';' || (cmd=='\n' && !repeat))
				printf("Error: missing command\n");

	    	//  prints error message that the input is not a letter otherwise
	    	else if(cmd!='\n') {
	        	printf("Error: %c is not a letter.\n", cmd);
	        	skipOverRestOfCommand();
	    	} 
		}

		//  resets repeat status of error message after newline	
		if(cmd=='\n')
	    	repeat=FALSE;
	
		//  gets the next character
		cmd = skipBlanks();
    }
}	


//  This function will skip any whitespaces or tabs before a character
int skipBlanks(void) {
    int c;
    c = getchar();
    while (c==' ' || c=='\t')
        c = getchar();
    return c;	
}

//  This function will skip all characters until it sees
//  a new line or a semi-colon
int skipOverRestOfCommand(void) {
    int c;
    c = getchar();
    while(c!=';' && c!='\n')
        c = getchar();
    return c;
}
