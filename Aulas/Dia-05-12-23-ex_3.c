#include <stdio.h>
#include <stdlib.h>

/* ALOCAÇÃO DINÂMICA  

*/
int main(){

    int tamanho = 5, novo_tamanho;

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    fflush(stdin);
    printf("\nEntre com o novo tamanho do vetor: ");
    scanf("%d", &novo_tamanho);

    vetor = (int *) realloc (vetor, novo_tamanho * sizeof(int));

    if (vetor == NULL){
        printf("\nErro na alocacao!");
        exit(0);
    }

    free(vetor);

    return 0;
}