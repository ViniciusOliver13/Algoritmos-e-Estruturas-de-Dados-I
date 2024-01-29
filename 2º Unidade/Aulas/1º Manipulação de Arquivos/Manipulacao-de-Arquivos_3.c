#include <stdio.h>
#include <stdlib.h>

int main(){

   int c;
   int nlinhas = 0;
   FILE *fp;     

   // Abre arquivo para leitura
   fp = fopen("entrada.txt", "rt");

   if(fp == NULL){
        printf("Nao foi possivel abrir o arquivo!");
        return 1;
   }

    while ( (c = fgetc(fp)) != EOF){
        if(c == '\n')
            nlinhas++;
    }

    fclose(fp);

    printf("Numero de linhas: %d\n", nlinhas);                                                                              

    return 0;
}