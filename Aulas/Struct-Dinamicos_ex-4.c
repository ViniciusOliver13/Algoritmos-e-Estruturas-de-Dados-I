#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Assunto: Structs Din�micas 

**** exemplo: Struct Funci�nario P�blico ****

*/

typedef struct funcionario{                     //Usando a fun��o "typedef" para renomear a struct "funcionario" para apenas
    char nome[40], email[50], trabalho[30];     //"funcionario".
    int idade, rg, telefone;
    float salario;
    
} funcionario;

void preencher(funcionario *funcionario){       //Fun��o para preencher "funcionario".
    printf("Informe o nome do funcion�rio: ");
    scanf("%[^\n]s", funcionario->nome);
    printf("Digite a idade: ");
    scanf("%d", &funcionario->idade);
    printf("Informe seu emprego: ");
    scanf(" %[^\n]", funcionario->trabalho);
    printf("Informe seu n�mero do RG: ");
    scanf("%d", &funcionario->rg);
    printf("Informe o n�mero de telefone: ");
    scanf("%d", &funcionario->telefone);
    printf("Digite o email: ");
    scanf(" %[^\n]", funcionario->email);
    printf("Informe seu sal�rio: ");
    scanf("%f", &funcionario->salario);
}
void imprimir(funcionario *funcionario){        //Fun��o para imprimir a struct "funcionario".
    printf("\nNome: %s\n", funcionario->nome);
    printf("Idade: %d\n", funcionario->idade);
    printf("Emprego: %s\n", funcionario->trabalho);
    printf("N�mero do RG: %d\n", funcionario->rg);
    printf("N�mero de telefone: %d\n", funcionario->telefone);
    printf("Email: %s\n", funcionario->email);
    printf("Seu sal�rio: R$%.2f", funcionario->salario);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    funcionario *funcionarioPublico = (funcionario*) malloc(sizeof(funcionario));   //Alocando mem�ria do tipo "funcionario" para a vari�vel "funcionarioPublico".

    if(funcionarioPublico == NULL){     //Verificando se a aloca��o ocorreu bem.
        exit(0);
    }

    preencher(funcionarioPublico);      //Fazendo as chamadas das fun��es.
    imprimir(funcionarioPublico);

    free(funcionarioPublico);           //Liberando mem�ria ao final da execu��o.

    return 0;    
}