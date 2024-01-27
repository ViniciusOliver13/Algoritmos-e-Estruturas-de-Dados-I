#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Estático

Declaração: struct nome{
                Bloco de variáveis[...];
            };
*/

struct aluno{          
    int idade;           //Declarando a struct "aluno"
    int matricula;  
    char nome[20];
    char email[50];
};

int main(){

    struct aluno estudante;                 //Declarando uma variável do "tipo" aluno.
    
    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", estudante.nome);
    printf("Digite a idade: ");             //Acessando o endereço de memória das variáveis da struct.
    scanf("%d", &estudante.idade);
    printf("Digite a matricula: ");
    scanf("%d", &estudante.matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante.email);

    return 0;
}