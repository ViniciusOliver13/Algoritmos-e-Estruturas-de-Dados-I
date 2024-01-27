#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Dinâmicas 

**** exemplo: Struct Professor ****

*/

struct professor{
    int  idade;
    char disciplina[30];        //Declarando a struct "professor".
    char nome[20];
    char email[50];
};

void preencher(struct professor *professor){        //Função para prencher a struct "professor".
    printf("Digite o nome do professor: ");
    scanf("%[^\n]s", professor->nome);          
    printf("Digite a idade: ");
    scanf("%d", &professor->idade);
    printf("Digite a disciplina: ");
    scanf(" %[^\n]", professor->disciplina);
    printf("Digite o email: ");
    scanf(" %[^\n]", professor->email);
}

void imprimir(struct professor *professor){         //Função para imprimir toda a struct "professor".
    printf("Nome: %s\n", professor->nome);
    printf("Idade: %d\n", professor->idade);
    printf("Disciplina: %s\n", professor->disciplina);
    printf("Email: %s\n", professor->email);
}

int main(){

    struct professor *professor = (struct professor*) malloc(sizeof(struct professor));     //Alocando memória do tipo struct "professor" para a variável "professor".

    if(professor == NULL){          //Verificando se a alocação ocorreu bem.
        exit(0);
    }

    preencher(professor);           //Fazendo as chamadas das funções.
    imprimir(professor);

    free(professor);                //Liberando memória ao final da execução.

    return 0;    
}