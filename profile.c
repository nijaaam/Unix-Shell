#include "profile.h"

void checkIfValidPath(){
    char *dir;
    char temp_path[1000];
    strcpy(temp_path,path);
    dir = strtok(temp_path, ":");
    while(dir != NULL){
        if (checkIfValidDIR(dir) == 0){
            break;
        }
        dir = strtok(NULL, ":");
    }
}

int checkIfValidDIR(char dir[]){
    DIR *directory = opendir(dir);
    if (directory == NULL){
        printf("ERROR in path\n");
        printf("ERROR: Not a valid directory: %s\n",dir);
        return 0;
    }
    return 1;
}

void readProfile(){
    FILE *file = fopen("profile","r");
    if (file == NULL){
        printf("ERROR in opening the file");
        exit(0);
    } else {
        char line[1000];
        while(fgets(line,1000,file) != NULL){
            applyVar(line);
        }
    }
    fclose(file);
    if (strcmp(home,"") == 0){
        printf("ERROR: HOME not set\n");
    }
    if (strcmp(path,"") == 0){
        printf("ERROR: PATH not set\n");
    }
}

void applyVar(char line[]){
    if (checkIfContains(line,"HOME=") || checkIfContains(line,"HOME =")){
        while(*line++ != '='){

        }
        if (line[strlen(line)-1] == '\n'){
           line[strlen(line)-1] = 0; 
        }
        strcpy(home,line);
        if (home[0] == ' '){
            int result = chdir(home+1);
            if (result == -1){
                printf("ERROR: Not a valid directory: %s\n",home);
                printf("HOME is set to current directory\n");
            }
        } else {
            int result = chdir(home);
            if (result == -1){
                printf("ERROR: Not a valid directory: %s\n",home);
                printf("HOME is set to current directory\n");
            }
        }
    } else if (checkIfContains(line,"PATH=") || checkIfContains(line,"PATH =")){
        while(*line++ != '='){

        }
        if (line[strlen(line)-1] == '\n'){
           line[strlen(line)-1] = 0; 
        }
        strcpy(path,line);
        checkIfValidPath();
    } else {
        if (strcmp(line,"\n") != 0){
            printf("ERROR Input not a HOME or PATH VAR %s\n",line);
        }
    }
}

int checkIfContains(char *line, char *var){
    if (strstr(line,var) != NULL){
        return 1;
    } else {
        return 0;
    }
}