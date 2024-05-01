#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    FILE *alunos = fopen("alunos.txt", "aw");

    char test, nome[45];
    int i;
    float notas[3];

    if(alunos == NULL){
        printf("Erro na abertura do arquivo!");
        exit(1);
    }

    printf("CASDASTRO DE ALUNOS\n-------------------\n");

    do{
        printf("Nome: ");
        scanf(" %[^\n]", nome);
        printf("Notas:\n");

        for(i = 0; i < 3; i++){
            printf("%dº nota: ", i + 1);
            scanf(" %f", &notas[i]);

        }

        fprintf(alunos, "Nome: %s\n1º nota: %.1f\n2º nota: %.1f\n3º nota: %.1f\n\n", nome, notas[0], notas[1], notas[2]);

        printf("Deseja continuar? [S/N] ");
        scanf(" %c", &test);
        system("cls");

    }while (test == 'S' || test == 's');
    
    printf("Alunos adicionados com sucesso!");
    fclose(alunos);

    return 0;
}