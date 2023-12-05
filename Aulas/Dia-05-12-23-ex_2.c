#include <stdio.h>
#include <stdlib.h>

/* ALOCAÇÃO DINÂMICA  

*/
int main(){

    int tamanho = 5, i;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    if (vetor == NULL){
        exit(0);
    }else{
        printf("ALOCACAO realizada com sucesso\n");
    }

    for ( i = 0; i < tamanho; i++){
        printf("Digite os valores do vetor: ");
        scanf("%d", vetor + i);
    }

    free(0);
    
    return 0;
}