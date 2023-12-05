#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *nome = (char *) malloc(50*sizeof(char));

    if (nome == NULL){
        exit(1);
    }

    printf("Digite seu nome: ");
    scanf("%[^\n]s", nome);

    nome = realloc(nome, strlen(nome) * sizeof(char));

    printf("SEU NOME: %s", nome);

    free(nome);

    return 0;
}   


