#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> 
#include <stdbool.h>
#include <string.h>

// Orden por longitud ascendente
int length_order(const void *a, const void *b){
    char *name_a = *(char **) a;
    char *name_b = *(char **) b;

    return strlen(name_a) - strlen(name_b);
}
// Orden por longitud descendente
int length_order_desc(const void *a, const void *b){
    char *name_a = *(char **) a;
    char *name_b = *(char **) b;

    return strlen(name_b) - strlen(name_a);
}
//Orden por valor numérico
int numeric_value_order(const void *a, const void *b){
    char *name_a = *(char **) a;
    char *name_b = *(char **) b;
    int sum_a = 0, sum_b = 0;

    for(int i = 0; i < strlen(name_a); i++){
        sum_a += name_a[i];
    }

    for(int i = 0; i < strlen(name_b); i++){
        sum_b += name_b[i];
    }

    return sum_a - sum_b;
}
// Orden por valor numérico descendente
int numeric_value_order_desc(const void *a, const void *b){
    char *name_a = *(char **) a; 
    char *name_b = *(char **) b;
    int sum_a = 0, sum_b = 0; 

    for(int i = 0; i < strlen(name_a); i++){
        sum_a += name_a[i];
    }

    for(int i = 0; i < strlen(name_b); i++){
        sum_b += name_b[i];
    }

    return sum_b - sum_a;
}
//Orden alfabético
int alfabetic_order(const void *a, const void *b){
    char *name_a = *(char **) a;
    char *name_b = *(char **) b;

    return strcmp(name_a,name_b);
}
//Orden alfabético descendente
int alfabetic_order_desc(const void *a, const void *b){
    char *name_a = *(char **) a;
    char *name_b = *(char **) b;

    return strcmp(name_b, name_a);
}

int main(int argc, char *argv[]){
    int opt;
    bool s = false, v = false, a = false, r = false;

    while((opt = getopt(argc, argv, "svar")) != -1){
        switch (opt){
            case 's':
                s = true;
            break;

            case 'v':
                v = true;
            break;
            
            case 'a':
                a = true;
            break;

            case 'r':
                r = true;
            break;
        }
    }
    // Lectura del archivo 
    FILE *file_in = fopen("CincoMilNombres.txt","r");
    char buffer[512];
    char *buffer_names[5163];
    int i_read = 0;

    // Almacenamiento de cada nombre en el archivo de CincoMilNombres.txt
    while(fgets(buffer,512,file_in)){
        buffer_names[i_read] = malloc(strlen(buffer) + 1);
        memcpy(buffer_names[i_read],buffer,strlen(buffer) + 1);
        i_read++;
    }
    fclose(file_in);
    // Creando archivo de salida
    FILE *file_out; 
    if (s){
        if(r){
            qsort(buffer_names,5163,sizeof(char *),length_order_desc);
            file_out = fopen("CincoMilNombres_OrdenS_R.txt","w");
        }
        else{
            qsort(buffer_names,5163,sizeof(char *),length_order);
            file_out = fopen("CincoMilNombres_OrdenS.txt","w");
        }
    }
    else if (v)
        if(r){
            qsort(buffer_names,5163,sizeof(char *),numeric_value_order_desc);
            file_out = fopen("CincoMilNombres_OrdenV_R.txt","w");
        }
        else{
            qsort(buffer_names,5163,sizeof(char *),numeric_value_order);
            file_out = fopen("CincoMilNombres_OrdenV.txt","w");
        }
    else if(a){
        if(r){
            qsort(buffer_names,5163,sizeof(char *),alfabetic_order_desc);
            file_out = fopen("CincoMilNombres_OrdenA_R.txt","w");
        }
        else{
            qsort(buffer_names,5163,sizeof(char *),alfabetic_order);
            file_out = fopen("CincoMilNombres_OrdenA.txt","w");
        }
    }
    //Escribiendo archivo de salida
    for(int i = 0; i < 5163; i++){
        fprintf(file_out, "%s",buffer_names[i]);
    }
    fclose(file_out);

    //Liberar memoria pedida con malloc
    for(int i = 0;i < 5163; i++){
        free(buffer_names[i]);
    }

    return 0;     
}