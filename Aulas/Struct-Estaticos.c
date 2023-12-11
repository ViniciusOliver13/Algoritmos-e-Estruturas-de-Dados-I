#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Estático

Declaração: struct nome{
                Bloco de variáveis[...];
            };
*/
struct aluno{
    int idade;
    int matricula;
    char nome[20];
    char email[50];
};
int main(){

    struct aluno estudante;
    
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante.nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante.idade);
    printf("Digite a matricula: ");
    scanf("%d", &estudante.matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante.email);

    return 0;
}