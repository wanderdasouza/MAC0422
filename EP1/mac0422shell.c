#include <signal.h>
#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>




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

char **isolateCommand(char **command) {

    char **isolated;
    int i;

    i = 1;
    isolated = malloc(32 * sizeof(char *));
    while (command[i] != NULL) {
        isolated[i-1] = command[i];
        i++;
    }

    isolated[i] = NULL;

    return isolated;
}


int main(int argc, char *argv[]) {

    char *input;
    char **command;
    int result;
    pid_t pidDoFilho;
    int status;
    
    while(1) {
        input = malloc(32 * sizeof(char));
        printf("mac422shell> ");
        scanf("%[^\n]", input); 
        /*
        input = readline("mac422shell> ") 
        */
        command = parser(input);        


        pidDoFilho = fork();
        if(pidDoFilho == 0){

            if (strcmp(command[0], "protegepracaramba") == 0) {
                result = chmod(command[1], 0000);
                _exit(result);
            }

            else if (strcmp(command[0], "liberageral") == 0)  {
                result = chmod(command[1], 0777);
                _exit(result);
            }

            else if (strcmp(command[0], "rodeveja") == 0) {
                result = execve(command[0], command);
                printf("execvp nao funcionou!\n"); 
                /*
                nao funcionou ja que essa linha nao sera executada caso o exec
                seja bem sucedido 
                */
                _exit(result);
            }
        }
        else{
            if (strcmp(command[0], "rode") == 0){
                signal(SIGCHLD, SIG_IGN); 
                /*
                este signal faz com que os processos defuntos sejam limpos da
                tabela de processos, evitando com que o numero de processos da tabela fique muito grande
                */
            }
            else waitpid(pidDoFilho, &status, WUNTRACED);
        }

        free(command);
        free(input);
    }
    
    return 0;
}