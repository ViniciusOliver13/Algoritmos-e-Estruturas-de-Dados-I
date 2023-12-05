#include <stdio.h>
#include <stdlib.h>

/* ALOCAÇÃO DINÂMICA COM REALLOC 
*/    
int main(){

    int tamanho = 5, novo_tamanho;

    int *vetor = (int *)malloc(tamanho * sizeof(int));       //Alocando o vetor com 5 posições.
    
    printf("\nEntre com o novo tamanho do vetor: ");
    scanf("%d", &novo_tamanho);                              //Informando o novo tamanho do vetor.  

    vetor = (int *) realloc (vetor, novo_tamanho * sizeof(int));    //Fazendo a realocação com a função "realloc".

    if (vetor == NULL){
        printf("\nErro na alocacao!");
        exit(0);
    }

    free(vetor);

    return 0;
}
