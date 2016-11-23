#include "shell.h"

void commandPrompt() {
    showHomeDir();
    char input[1000], * arg[50];
    fgets(input, 1000, stdin);
    int len = strlen(input);
    len--;
    input[len] = 0;
    if (input[0] == '$') {
        applyVar(input+1);
    } else {
        getArguments(input, arg);
        if (strcmp(arg[0], "cd") == 0) {
            changeDir(arg);
        } else if (searchPath(arg[0])) {
            executeCommand(arg);
        } else {
            printf("%s: command not found\n", arg[0]);
        }
    }
}

void showHomeDir() {
    char * dir;
    dir = (char * ) malloc(100 * sizeof(char));
    getcwd(dir, 100);
    printf("%s>", dir);
    free(dir);
}