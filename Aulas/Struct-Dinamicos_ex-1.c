#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Dinâmico

**** Declaração de uma Structs usando ponteiros ****

*/

struct aluno{
    int idade;
    int matricula;          //Declarando a struct "aluno"
    char nome[20];
    char email[50];
};

int main(){

    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));    //Alocando memória do tipo "aluno" para variável "estudante". 

    if(estudante == NULL){                  //Verificando se a alocação ocorreu bem.
        exit(0);
    }

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante->nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);         //Acessando os variáveis da struct usando o operador "->". 
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);

    free(estudante);                        //Liberando memória.

    return 0;    
}
