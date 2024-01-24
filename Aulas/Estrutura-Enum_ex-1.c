#include<stdio.h>

#define TRUE 0      //Declarando 2(duas) constantes.
#define FALSE 1



int main(void){
    int resposta;

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