#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union genero{       //Estrutura Union para armazenar o gênero de uma pessoa.
    char masculino[10];
    char feminino[9];

} Genero;

typedef struct pessoa{      //Declarando uma struct "pessoa" para apenas "Pessoa" com a função typedef.
    char nome[30];
    int idade;
    Genero gen;
} Pessoa;

void preenche(Pessoa *p){
    int op;

    printf("Informe seu nome: ");
    scanf(" %[^\n]", p->nome);
    printf("Informe a idade: ");
    scanf("%d", &p->idade);
    printf("Digite 0 para MASCULINO e 1 para FEMININO: ");
    scanf("%d", &op);

    if (op){                                        //Isso significa dizer que se "op" for "verdade"(ou seja 1) vai 
        strcpy(p->gen.feminino, "FEMININO");        //ser passado para a union "Genero" o conteúdo "FEMININO".  
    }else{                                          //Assim, se "op" for "falso"(ou seja != 1) vai ser passado "MASCULINO".
        strcpy(p->gen.masculino, "MASCULINO");
    }
}

void imprimir(Pessoa *p){                      //Função para imprimir o conteúdo da struct "Pessoa".
    printf("================\n");    
    printf("Nome: %s\n", p->nome);
    printf("Idade: %d\n", p->idade);
    printf("Genero: %s\n", p->gen.feminino);
    printf("================");
}

int main(){

    Pessoa *pessoa = malloc(sizeof(Pessoa));   //Alocando memória para a variável "pessoa".

    preenche(pessoa);          
    imprimir(pessoa);

    free(pessoa);       //Liberando memória ao fim da execução.

    return 0;
}