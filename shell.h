#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "execute.h"

void commandPrompt();
/*This function gets the user and input, parses it
into arguments, checks if the program in the PATH and calls executeCommand

*/
void showHomeDir();
//Get the current working directory and prints it