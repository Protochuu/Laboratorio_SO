#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    pid_t pid;
    pid = fork();
    if (pid != 0){
        printf("Proceso padre: %d \n Proceso hijo: %d \n", getpid(), pid);
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid1 = fork();
            if(pid1 == 0){
                break;                
            }
            else{
                printf("Proceso hijo %d pid: %d",i,pid1);
            }
        }
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid2 = fork();
            if(pid2 == 0){
                break;                
            }
            else{
                printf("Proceso hijo %d pid: %d",i,pid2);
            }
        }
        sleep(5);
        for (int i = 0; i < 3; i++){
            pid_t pid3 = fork();
            if(pid3 == 0){
                break;                
            }
            else{
                printf("Proceso hijo %d pid: %d",i,pid3);
            }
        }
    }
    return 0;
}