#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Din�micas 

**** exemplo: Struct Professor ****

*/

struct professor{
    int  idade;
    char disciplina[30];        //Declarando a struct "professor".
    char nome[20];
    char email[50];
};

void preencher(struct professor *professor){        //Fun��o para prencher a struct "professor".
    printf("Digite o nome do professor: ");
    scanf("%[^\n]s", professor->nome);          
    printf("Digite a idade: ");
    scanf("%d", &professor->idade);
    printf("Digite a disciplina: ");
    scanf(" %[^\n]", professor->disciplina);
    printf("Digite o email: ");
    scanf(" %[^\n]", professor->email);
}

void imprimir(struct professor *professor){         //Fun��o para imprimir toda a struct "professor".
    printf("Nome: %s\n", professor->nome);
    printf("Idade: %d\n", professor->idade);
    printf("Disciplina: %s\n", professor->disciplina);
    printf("Email: %s\n", professor->email);
}

int main(){

    struct professor *professor = (struct professor*) malloc(sizeof(struct professor));     //Alocando mem�ria do tipo struct "professor" para a vari�vel "professor".

    if(professor == NULL){          //Verificando se a aloca��o ocorreu bem.
        exit(0);
    }

    preencher(professor);           //Fazendo as chamadas das fun��es.
    imprimir(professor);

    free(professor);                //Liberando mem�ria ao final da execu��o.

    return 0;    
}