#include "profile.h"
#include "shell.h"

int main() {
    readProfile();
    while(1){
        commandPrompt();    
    }
    return 0;
}
