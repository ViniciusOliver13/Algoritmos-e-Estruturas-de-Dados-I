#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct frutas{
    char nome[25];
    float preco;    
} Frutas;

int main(){
    setlocale(LC_ALL, "Portuguese");

    FILE *lista = fopen("frutas.txt", "aw");
    Frutas escolha;
    char test;

    if(lista == NULL){
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    printf("\033[1m\033[33m=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n B A N C A  D E  F R U T A S\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\033[0m");

    do{
        printf("\033[1mNome da fruta:\n>>> ");
        scanf(" %[^\n]", escolha.nome);
        printf("Preço:\n>>> R$");
        scanf(" %f", &escolha.preco);

        strupr(escolha.nome);

        fprintf(lista, "Nome: %s\nPreço: R$%.2f\n\n", escolha.nome, escolha.preco);
        printf("%s adicionada!", escolha.nome);

        printf("\nDeseja continuar? [S/N] ");
        scanf(" %c", &test);

    }while (test == 'S' || test == 's');

    if(fclose(lista) == 0){
        printf("   Alterações salvas!\n  ===== VOLTE SEMPRE! =====\033[0m");
    }

    return 0;
}