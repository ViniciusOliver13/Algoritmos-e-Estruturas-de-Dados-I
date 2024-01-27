#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Assunto: Structs Dinâmicas 

**** exemplo: Struct Funciónario Público ****

*/

typedef struct funcionario{                     //Usando a função "typedef" para renomear a struct "funcionario" para apenas
    char nome[40], email[50], trabalho[30];     //"funcionario".
    int idade, rg, telefone;
    float salario;
    
} funcionario;

void preencher(funcionario *funcionario){       //Função para preencher "funcionario".
    printf("Informe o nome do funcionário: ");
    scanf("%[^\n]s", funcionario->nome);
    printf("Digite a idade: ");
    scanf("%d", &funcionario->idade);
    printf("Informe seu emprego: ");
    scanf(" %[^\n]", funcionario->trabalho);
    printf("Informe seu número do RG: ");
    scanf("%d", &funcionario->rg);
    printf("Informe o número de telefone: ");
    scanf("%d", &funcionario->telefone);
    printf("Digite o email: ");
    scanf(" %[^\n]", funcionario->email);
    printf("Informe seu salário: ");
    scanf("%f", &funcionario->salario);
}
void imprimir(funcionario *funcionario){        //Função para imprimir a struct "funcionario".
    printf("\nNome: %s\n", funcionario->nome);
    printf("Idade: %d\n", funcionario->idade);
    printf("Emprego: %s\n", funcionario->trabalho);
    printf("Número do RG: %d\n", funcionario->rg);
    printf("Número de telefone: %d\n", funcionario->telefone);
    printf("Email: %s\n", funcionario->email);
    printf("Seu salário: R$%.2f", funcionario->salario);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    funcionario *funcionarioPublico = (funcionario*) malloc(sizeof(funcionario));   //Alocando memória do tipo "funcionario" para a variável "funcionarioPublico".

    if(funcionarioPublico == NULL){     //Verificando se a alocação ocorreu bem.
        exit(0);
    }

    preencher(funcionarioPublico);      //Fazendo as chamadas das funções.
    imprimir(funcionarioPublico);

    free(funcionarioPublico);           //Liberando memória ao final da execução.

    return 0;    
}