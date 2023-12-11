#include <stdio.h>
#include <stdlib.h>

/* Assunto: Structs Dinâmicas 

*/

struct professor{
    int  idade;
    char disciplina[30];
    char nome[20];
    char email[50];
};
void preencher(struct professor *professor){
    printf("Digite o nome do professor: ");
    scanf("%[^\n]s", professor->nome);
    printf("Digite a idade: ");
    scanf("%d", &professor->idade);
    printf("Digite a disciplina: ");
    scanf(" %[^\n]", professor->disciplina);
    printf("Digite o email: ");
    scanf(" %[^\n]", professor->email);
}
void imprimir(struct professor *professor){
    printf("Nome: %s\n", professor->nome);
    printf("Idade: %d\n", professor->idade);
    printf("Disciplina: %s\n", professor->disciplina);
    printf("Email: %s\n", professor->email);
}
int main(){

    struct professor *professor = (struct professor*) malloc(sizeof(struct professor));

    if(professor == NULL){
        exit(0);
    }

    preencher(professor);
    imprimir(professor);

    free(professor);

    return 0;    
}