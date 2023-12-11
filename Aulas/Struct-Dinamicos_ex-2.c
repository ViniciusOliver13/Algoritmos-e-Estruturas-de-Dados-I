#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Din�micas 

**** exemplo: Struct Aluno ****
*/

struct aluno{
    int idade;
    int matricula;      //Declarando a struct.
    char nome[20];
    char email[50];
};
void preencher(struct aluno *estudante){        //Passando para a fun��o "preencher" a "struct aluno". 
    printf("Digite o nome do aluno: ");         
    scanf("%[^\n]s", estudante->nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);             //Preenchendo os campos das vari�veis.    
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);
}

void imprimir(struct aluno *estudante){         //Fun��o imprimir recebe a "struct aluno".
    printf("Nome: %s\n", estudante->nome);      //Usando o operador "->" para manipular as vari�veis.
    printf("Idade: %d\n", estudante->idade);
    printf("Matricula: %d\n", estudante->matricula);
    printf("Email: %s\n", estudante->email);
}

int main(){

    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));     //Alocando mem�ria do tipo "aluno" para a vari�vel "estudante".

    if(estudante == NULL){         //Verificando se a aloca��o ocorreu bem.
        exit(0);
    }

    preencher(estudante);         //Fazendo as chamadas das fun��es.
    imprimir(estudante);    

    free(estudante);              //Liberando mem�ria ao final da execu��o. 

    return 0;    
}