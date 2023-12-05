#include <stdio.h>
#include <stdlib.h>

//  ALOCAÇÃO DINÂMICA

int main(){

    int *vetor;

    vetor = malloc(3 * sizeof(int));     // Função malloc: Usada para alocar memória em tempo de execução. 

    if(vetor == NULL){
        printf("Erro na alocacao!");
        exit(1);
    }else{
        printf("Memoria alocada");
    }

    free(vetor);      //Liberando a memória alocada para a variável vetor.

    return 0;
}   


