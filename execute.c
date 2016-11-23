#include "execute.h"

void getArguments(char input[], char *arg[]){
    char *token;
    int j = 0;
    token = strtok(input, " ");
    while(token != NULL){
        arg[j] = token;
        j++;
        token = strtok(NULL, " ");
    }
    arg[j] = '\0';
}

void executeCommand(char **arg){
    pid_t child = fork();
    if (child == 0){
        int status = execvp(*arg, arg);
        if (status < 0){
            printf("ERROR: Execution Failed\n");
            exit(1);
        }
    } else if (child < 0){
        printf("ERROR: Forking failed, < 0\n");
        exit(1);
    } else {
        waitpid(child, NULL, 0);
    } 
}

void changeDir(char **arg){
    if (arg[1] == NULL || strcmp(arg[1], "~") == 0){
        chdir(home);
    } else {
        int res = chdir(arg[1]);
        if (res != 0){
            printf("ERROR: cd: %s: No such file or directory\n",arg[1]);
        }
    }
}

int IsInDir(char dir[], char program[]){
    struct dirent *entry;
    DIR *directory = opendir(dir);
    if (directory != NULL){
        while ((entry = readdir(directory)) != NULL) {
            if (strcmp(program, entry-> d_name) == 0){
                return 1;
            }
        }
        closedir(directory);
    } else {
        //printf("Cannot open directory %s\n",dir);
    }
    return 0;
}

int searchPath(char input[]){
    char *dir;
    char temp_path[1000];
    strcpy(temp_path,path);
    dir = strtok(temp_path, ":");
    while(dir != NULL){
        if (IsInDir(dir,input)){
            return 1;
        }
        dir = strtok(NULL, ":");
    }
    return 0;
}