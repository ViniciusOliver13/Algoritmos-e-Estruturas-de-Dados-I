#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Est�tico

Declara��o: struct nome{
                Bloco de vari�veis[...];
            };
*/

struct aluno{          
    int idade;           //Declarando a struct "aluno"
    int matricula;  
    char nome[20];
    char email[50];
};

int main(){

    struct aluno estudante;                 //Declarando uma vari�vel do "tipo" aluno.
    
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante.nome);
    printf("Digite a idade: ");             //Acessando o endere�o de mem�ria das vari�veis da struct.
    scanf("%d", &estudante.idade);
    printf("Digite a matricula: ");
    scanf("%d", &estudante.matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante.email);

    return 0;
}