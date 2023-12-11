#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Dinâmicas 

*/

struct aluno{
    int idade;
    int matricula;
    char nome[20];
    char email[50];
};
void preencher(struct aluno *estudante){
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante->nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);
}
void imprimir(struct aluno *estudante){
    printf("Nome: %s\n", estudante->nome);
    printf("Idade: %d\n", estudante->idade);
    printf("Matricula: %d\n", estudante->matricula);
    printf("Email: %s\n", estudante->email);
}
int main(){

    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));

    if(estudante == NULL){
        exit(0);
    }

    preencher(estudante);
    imprimir(estudante);

    free(estudante);

    return 0;    
}