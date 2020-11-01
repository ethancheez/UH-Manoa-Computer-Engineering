/*      File : readcmd.c        *
 *      By   :                  *
 *      login:                  *
 *      team :                  *
 *      Date :                  */

/*
 * Read a command, skipping over leading blanks and any trailing
 * characters.
 */

#include <stdio.h>

int skipBlanks(void);
int skipOverRestOfCommand(void);

int main()
{
  int cmd;

        cmd = skipBlanks();
        while (cmd != EOF)
        {
                printf("The command is: %c\n", cmd);
                skipOverRestOfCommand();
                cmd = skipBlanks();
    
        }
}

int skipBlanks(void)
{
  int c;

        c = getchar();
        while (c == ' ')
                c = getchar();
        return c;
}

int skipOverRestOfCommand(void)
{
  int c;
  
        c = getchar();
        while (c != '\n')
                c = getchar();
        return c;
}