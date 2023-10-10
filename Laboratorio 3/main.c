#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>

bool execute_command(char *argv[]){
    if(!strcmp(argv[0], "exit")){
        return false;
    }

    pid_t pid = fork();

    if(pid == -1){
        printf("Error al ejecutar el comando (⊙ө⊙)!\n");
        exit(0);
    }

    if(pid){
        //Proceso padre espera que proceso hijo termine
        waitpid(pid,NULL,0);
    }
    else {
        //Proceso hijo ejecuta comando
        if(execvp(argv[0], argv) == -1){
            printf("Comando no existe (⊙ө⊙)!\n");
            exit(1);
        }
    }
    return true;
}

bool display_prompt(){
    //prompt
    printf("( ˘ ⊖ ˘)/ Que deseas bellaca/o? " );

    char buffer[256];
    char *argv [64];

    fgets(buffer,256,stdin);
    //Quitar salto de línea
    strtok(buffer,"\n");
    //Separar argumentos
    char *token = strtok(buffer," ");
    int argc = 0;
    while (token != NULL){
        argv[argc] = token;
        argc++;

        token = strtok(NULL," ");
    }
    argv[argc] = NULL;

    return execute_command(argv);
}

int main(int argc, char **argv){
    while(display_prompt());

    return 0;
}