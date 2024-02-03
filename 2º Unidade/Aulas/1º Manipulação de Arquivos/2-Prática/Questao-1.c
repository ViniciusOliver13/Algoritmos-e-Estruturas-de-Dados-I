#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    FILE *funcionarios = fopen("funcionarios.txt", "aw");

    char nome[40];
    int i, tam, id;
    float salario;

    if(funcionarios == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    printf("Qual a quantidade de funcion�rios? ");
    scanf("%d", &tam);
    system("cls");

    for(i = 0; i < tam; i++){
        printf("Qual o nome do %d� funcion�rio? ", i + 1);
        scanf(" %[^\n]", nome);
        printf("Seu id: ");
        scanf(" %d", &id);
        printf("Informe o sal�rio: R$");
        scanf(" %f", &salario);

        fprintf(funcionarios, "Nome: %s\nid: %d\nSal�rio: R$%.2f\n\n", nome, id, salario);
        system("cls");
    }

    printf("Arquivo de texto modificado!\nFim da execu��o!");
    
    fclose(funcionarios);

    return 0;
}