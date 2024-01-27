#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *nome = (char *) malloc(50*sizeof(char));

    if (nome == NULL){
        exit(1);
    }

    printf("Digite seu nome: ");
    scanf("%[^\n]s", nome);        //Lendo o nome completo de uma pessoa com espaços.

    nome = realloc(nome, strlen(nome) * sizeof(char));       //Usando a função "realloc" para realocar a memória de acordo com
                                                             //o tamanho do nome.    
    printf("SEU NOME: %s", nome);                            //Usando a função "strlen()" para saber o tamanho de toda a string.    

    free(nome);

    return 0;
}   
