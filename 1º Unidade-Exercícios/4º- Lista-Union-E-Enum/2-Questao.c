#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef union tipo{               //Declarando a union "Tips" que pode armazenar a palavra: "alimento", 
    char alimento[9];             //"bebida" ou "eletrônico".  
    char bebida[7];
    char eletronico[11];
} Tips;

typedef struct produto{         //Declarando a struct "Produto".
    char nome[20];
    float preco;
    Tips tipo;
} Produto;

void preenche(Produto *p){      //Função para preencher a struct "Produto" e também um "menu" inicial.
    int opcao;

    printf("===============\nC A D A S T R O\n      D E\nP R O D U T O S\n===============\n");
    printf("Nome: ");
    scanf(" %[^\n]", p->nome);          
    printf("Preço: R$");
    scanf(" %f", &p->preco);
    printf("Tipo:\n  [1] Alimento\n  [2] Bebida\n  [3] Eletrônico\n>> ");
    scanf("%d", &opcao);        

    switch (opcao){             //Usando o "switch()" saber qual foi a opção selecionada pelo usuário.
        case 1:
            strcpy(p->tipo.alimento, "ALIMENTO");           //Usando a função "strcpy()" para fazer uma cópia das
            break;                                          //strings de cada tipo.
        case 2:
            strcpy(p->tipo.bebida, "BEBIDA");
            break;
        case 3:
            strcpy(p->tipo.eletronico, "ELETRÔNICO");
            break;
    }
}
void imprimir(Produto *p){              //Função para imprimir o conteúdo da struct "Produto".
    system("cls");
    printf("----------------\nDADOS DO PRODUTO\n----------------\n");
    printf("Nome: %s\n", p->nome);
    printf("Preço: R$%.2f\n", p->preco);
    printf("Tipo: %s\n", p->tipo.eletronico);

}

int main(){
    setlocale(LC_ALL,"Portuguese");     

    Produto *produto = malloc(sizeof(Produto));     //Alocando memória para a variável "produto".

    preenche(produto);
    imprimir(produto);

    free(produto);      //Liberando memória ao fim da execução.

    return 0;
}