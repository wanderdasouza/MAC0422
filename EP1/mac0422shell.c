#include <signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>



 char **parser(char *input) {
    char **command;
    char *tokenized;
    int i;

    command = malloc(32 * sizeof(char *));

    tokenized = strtok(input, " ");
    i = 0;

    while(tokenized != NULL) {
        command[i] = tokenized;
        i = i + 1;
        tokenized = strtok(NULL, " ");
    }

    command[i] = NULL;
    
    return command;

}


int main() {

    char *input;
    char **command;
    int result;
   
    
    while(1) {
        input = malloc(32 * sizeof(char));
        scanf("%[^\n]", input);

        command = parser(input);        

        if (strcmp(command[0], "protegepracaramba") == 0) {
            result = chmod(command[1], 0000);
        }

        else {
            if (strcmp(command[0], "liberageral") == 0) {
                result = chmod(command[1], 0777);
            }

            else {
                if (1) {

                }

                else {

                }
            }
        }

        free(command);
        free(input);

        return 0;
    }
    
    return 0;
}