#include<stdio.h>

//Declarando a estrutura Enumeração ou Enum.
typedef enum bool{TRUE, FALSE} Bool;

int main(void){
    Bool resposta;

    printf("Voce gosta de algoritmo? \n0-True \n1-False\n>> ");
    scanf("%d",&resposta);

    if (resposta==TRUE){
        printf("Parabens pela escolha! :)\n");
    }
    else if(resposta==FALSE){
        printf("Ahh e assim mesmo :(\n");
    }

    return 0;
}