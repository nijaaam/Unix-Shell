#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

//This header file has functions and global variables that are necessary to load a profile
char home[1000]; //Contains the HOME Variable
char path[1000]; //Contains the PATH Varibale

void readProfile(); 
//This function reads a file line by line and passes it applyVar() function and check if the env variables are set
void applyVar(char buff[]);
/*This function sets the HOME and PATH Varible
To set a HOME directory it copies the line to home global variable and changes the current directory
To set a PATH directory it copies the line to path global variable and checks if the path is valid

*/
int checkIfContains(char *line, char *var);
//Checks if the variable is the line (user input)
void checkIfValidPath();
//Checks if the path valid
int checkIfValidDIR(char dir[]); 
//Checks if the directory is valid