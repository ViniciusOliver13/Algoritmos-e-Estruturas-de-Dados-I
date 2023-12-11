#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Dinâmicas 

**** exemplo: Struct Aluno ****
*/

struct aluno{
    int idade;
    int matricula;      //Declarando a struct.
    char nome[20];
    char email[50];
};
void preencher(struct aluno *estudante){        //Passando para a função "preencher" a "struct aluno". 
    printf("Digite o nome do aluno: ");         
    scanf("%[^\n]s", estudante->nome);
    printf("Digite a idade: ");
    scanf("%d", &estudante->idade);             //Preenchendo os campos das variáveis.    
    printf("Digite a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Digite o email: ");
    scanf(" %[^\n]", estudante->email);
}

void imprimir(struct aluno *estudante){         //Função imprimir recebe a "struct aluno".
    printf("Nome: %s\n", estudante->nome);      //Usando o operador "->" para manipular as variáveis.
    printf("Idade: %d\n", estudante->idade);
    printf("Matricula: %d\n", estudante->matricula);
    printf("Email: %s\n", estudante->email);
}

int main(){

    struct aluno *estudante = (struct aluno*) malloc(sizeof(struct aluno));     //Alocando memória do tipo "aluno" para a variável "estudante".

    if(estudante == NULL){         //Verificando se a alocação ocorreu bem.
        exit(0);
    }

    preencher(estudante);         //Fazendo as chamadas das funções.
    imprimir(estudante);    

    free(estudante);              //Liberando memória ao final da execução. 

    return 0;    
}