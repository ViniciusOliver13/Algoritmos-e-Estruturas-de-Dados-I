#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int tam, i, *point;

    printf("Qual é o tamanho do vetor? ");
    scanf("%d", &tam);

    int vet[tam];
    point = vet;

    printf("Informe os %d elementos do vetor:\n", tam);
    for(i = 0; i < tam; i++){
        printf("%dº Posição: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("\nOs elementos que foram inseridos:\n");

    //IMPRIMINDO O CONTEÚDO DO VETOR
    for(i = 0; i < tam; i++){
        printf("%dº Elemento: %d\n", i + 1, *(vet + i));
    }

    return 0; 
}