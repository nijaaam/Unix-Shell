#include <string.h>
#include "profile.h"
#include <dirent.h>
#include <sys/wait.h>

void getArguments(char input[], char *arg[]); 
//This function takes the user input and an pointer to an array as arguments. Using strtok function it seperates the input string into tokens and copies it to the arr array
void executeCommand(char **arg); 
//This function takes the arguments (arg) pointer. It forks a new process and executes the process using execvp.
void changeDir(char **arg); 
//This function changes the current working directory to the argument specified using the chdir funcion
int IsInDir(char dir[], char program[]); 
//This function checks if the program in the specified directory
int searchPath(char input[]);
//This function checks if the program is in the PATH