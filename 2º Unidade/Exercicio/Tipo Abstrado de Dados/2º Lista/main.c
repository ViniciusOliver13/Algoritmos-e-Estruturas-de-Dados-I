#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ingresso.c"

int main(){
    setlocale(LC_ALL, "Portuguese");

    int tam;

    printf("Qual o número de ingressos? ");
    scanf("%d", &tam);

    Ingresso *token = (Ingresso*) malloc(sizeof(Ingresso) * tam);

    if(token == NULL){
        printf("Erro na alocação!");
        exit(1);
    }
    
    preencher(token, tam);
    imprimir(token, tam);
    novo_valor(token, tam);
    Preco_menorEmaior(token, tam);

    free(token);

    return 0;
}