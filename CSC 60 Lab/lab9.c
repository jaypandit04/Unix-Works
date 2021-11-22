/* Author(s): Ruthann Biel
 *
 * Jay Pandit                      	
 * This is csc60mshell.c
 * This is lab9.c the csc60mshell
 * This program serves as the base for doing labs 9 and 10.
 * Student is required to use this program to build a mini shell
 * using the specification as documented in the directions.
 * Date: Spring 2021
 */

#include "lab9_10.h"


/* ----------------------------------------------------------------- */
/*                  The main program starts here                     */
/* ----------------------------------------------------------------- */
int main(void)
{
    char cmdline[MAXLINE];
    char *argv[MAXARGS];
    int argc;

    // Loop forever to wait and process commands 
    while (TRUE) 
    {
	printf("\ncsc60msh> ");

	/* read the command the user types in */
	fgets(cmdline, MAXLINE, stdin);

	/* Call ParseLine to build argc/argv; their limits declared above */
        // You write this call
    argc = ParseLine(cmdline,argv);
    
	// REQUIRED: Just-to-make-sure printfs 
        printf("Argc = %i \n",  argc);
	int i;
	for(i = 0; i < argc; i++)
	{
            printf ("Argv %i = %s \n", i, argv[i]);
	}
	
	// If user hits enter key without a command, continue to loop again at the beginning 
	// You write this line.  Hint: if argc is zero, no command declared */

     if(argc==0)
         continue; 
	
	// Handle build-in command: exit, pwd, or cd 
        // See the directions for the algorithms to do these 3 commands.
	
        if(strcmp(argv[0],"exit")==0)
        {
          _exit(EXIT_SUCCESS);
        }
        else if(strcmp(argv[0],"pwd")==0)
        {
          char path[MAX_PATH_LENGTH];
          getcwd(path,MAX_PATH_LENGTH);
          printf("%s",path); 
          continue;   
         }
        else if(strcmp(argv[0],"cd")==0)
        {
          char *dir;
          if(argc==1)
            {
               getenv("HOME");
               dir = getenv("HOME");    
            }
            else
               {
                 dir = argv[1];      
               }
            
           if(chdir(dir) != 0)
           {     
                perror("Error changing directory \n");
                _exit(EXIT_FAILURE);
            }
            continue; 
                
        }
        
        /* Else, fork off a process */
        else
  	{
           // RunExternalCommand(int argc, char argv);
			
	}      /* end of the if-else-if */

    }	       /* end of the while loop */
}   	       /* end of main */


