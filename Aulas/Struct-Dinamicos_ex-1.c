#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Din�mico

**** Declara��o de uma Structs usando ponteiros ****

*/

struct aluno{
    int idade;
    int matricula;          //Declarando a struct "aluno"
    char nome[20];
    char email[50];
};

int main(){

    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));    //Alocando mem�ria do tipo "aluno" para vari�vel "estudante". 

    if(estudante == NULL){                  //Verificando se a aloca��o ocorreu bem.
        exit(0);
    }

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante->nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);         //Acessando os vari�veis da struct usando o operador "->". 
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);

    free(estudante);                        //Liberando mem�ria.

    return 0;    
}
