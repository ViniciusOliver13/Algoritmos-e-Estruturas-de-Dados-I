#include <stdio.h>
#include <stdlib.h>

/* ALOCAÇÃO DINÂMICA  

*/
int main(){

    int tamanho = 5, i;
    int *vetor = (int *)malloc(tamanho * sizeof(int)); //Alocando o vetor com 5 posições.

    if (vetor == NULL){
        exit(0);       //Função "exit()" para finalizar a execução do código.
    }else{
        printf("ALOCACAO realizada com sucesso\n");
    }

    for ( i = 0; i < tamanho; i++){
        printf("Digite os valores do vetor: ");        //Preenchedo o vetor com números inteiros.
        scanf("%d", vetor + i);
    }

    free(0);
    
    return 0;
}
