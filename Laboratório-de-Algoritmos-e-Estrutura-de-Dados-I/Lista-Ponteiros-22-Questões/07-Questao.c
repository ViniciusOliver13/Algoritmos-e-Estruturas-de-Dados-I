#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int tam, i, *point;

    printf("Qual � o tamanho do vetor? ");
    scanf("%d", &tam);

    int vet[tam];
    point = vet;

    printf("Informe os %d elementos do vetor:\n", tam);
    for(i = 0; i < tam; i++){
        printf("%d� Posi��o: ", i + 1);
        scanf("%d", &vet[i]);
    }
    
    printf("\nOs elementos que foram inseridos:\n");

    //IMPRIMINDO O CONTE�DO DO VETOR
    for(i = 0; i < tam; i++){
        printf("%d� Elemento: %d\n", i + 1, *(vet + i));
    }

    return 0; 
}