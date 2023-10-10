#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

    pid_t pid;
    pid = fork();
    if (pid != 0){
        printf("Proceso padre: %d \n Proceso hijo: %d \n", getpid(), pid);
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid1 = fork();
            if(pid1 == 0){
                exit(0);                
            }
            else{
                printf("Proceso hijo %d pid 1: %d \n",i,pid1);
            }
        }
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid2 = fork();
            if(pid2 == 0){
                exit(0);                
            }
            else{
                printf("Proceso hijo %d pid 2: %d \n",i,pid2);
            }
        }
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid3 = fork();
            if(pid3 == 0){
                exit(0);                
            }
            else{
                printf("Proceso hijo %d pid 3: %d \n",i,pid3);
            }
        }
    }
    return 0;
}