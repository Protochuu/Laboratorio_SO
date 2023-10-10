#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int num = 256, sum_cubos = 0;
    for (int i = 1; i < 257; i++){
        sum_cubos += i*i*i;
    }
    printf("El resultado de la suma de cubos es: %d \n", sum_cubos);

    pid_t pid = fork();
    int sum_par = 0, sum_impar = 0;
    while (num > 0){
        if (pid != 0){
            if(num % 2 == 0){
                sum_par += num*num*num; 
            }
        }
        else{
            if(num % 2 != 0){
                sum_impar += num*num*num; 
            }
        }
        num--;
    }
    if (pid != 0){
        printf("El resultado de las sumas pares:%d \n", sum_par);    
        printf("Padre: El resultado de las suma total:%d \n", sum_par + sum_impar); 
    }
    else{
        printf("El resultado de las sumas impares:%d \n",sum_impar);
        printf("Hijo: El resultado de las suma total:%d \n", sum_par + sum_impar); 
    }

    return 0;
}