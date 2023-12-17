#include <stdio.h>
#include <stdlib.h>

int main(){

    int *elemens = (int*) malloc(100 * sizeof(int));
    int i, tam, maior;

    if (elemens == NULL){
        printf("Erro na alocacao!");
        free(elemens);
        exit(1);
    }
    

    printf("Digite um intervalo entre 1 e 100: ");
    scanf("%d",&tam);

    for ( i = 0; i < tam; i++){
        printf("Digite o valor do %d elemento: ", i + 1);
        scanf("%d", &elemens[i]);

        if(i == 0){
            maior = elemens[i];
        }else if (maior < elemens[i]){
            maior = elemens[i];
        }
    }

    printf("O maior valor foi %d.", maior);

    return 0;
}