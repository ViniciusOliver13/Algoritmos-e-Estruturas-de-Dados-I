#include <stdio.h>
#include <stdlib.h>

typedef union documentos{
    char rg[15];
    char cpf[15];
} Documentos;

// Estrutura Union
typedef struct pessoa{
    char nome[20];
    int idade;
    Documentos doc;     //Variável para armazenar o CPF ou RG.
} Pessoa;

void dados_pessoa(Pessoa *p){
    int opcao;

    printf("Nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Idade: ");
    scanf("%d", &p->idade);
    printf("Digite 1 para CPF ou 0 para RG:");
    scanf("%d", &opcao);
    if (opcao){
        scanf(" %[^\n]", p->doc.cpf);
    }else{
        scanf(" %[^\n]", p->doc.rg);
    }

};

int main(void){

    Pessoa *pessoa = malloc(sizeof(Pessoa));
    dados_pessoa(pessoa);
    
    printf("CPF= %s\nRG= %s", pessoa->doc.cpf, pessoa->doc.rg);
    
    free(pessoa);

    return 0;
}