#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"      //TAD: Aluno

struct aluno{
    char nome[20];
    int matricula;
    float IRA;
};

Aluno *recebe_dados(void){
    Aluno *estudante = (Aluno*) malloc(sizeof(Aluno));

    if(estudante == NULL){
        printf("Sem memoria!");
        exit(1);
    }
    
    printf("Informe o nome do aluno: ");
    scanf(" %[^\n]", estudante->nome);
    printf("Informe a matricula: ");
    scanf("%d", &estudante->matricula);
    printf("Informe o IRA: ");
    scanf(" %f", &estudante->IRA);

    return estudante;
}

Aluno *matricular_alunos(int tam){
    Aluno *p = (Aluno*)malloc(tam * sizeof(Aluno));
    int i;
    
    for (i = 0; i < tam; i++){
        p[i] = *recebe_dados();
    }
    
    return p;
}

void imprimir(Aluno *p, int tam){
    int i;

    system("cls");

    for ( i = 0; i < tam; i++){
        printf("Nome: %s\n", p[i].nome);
        printf("Matricula: %d\n", p[i].matricula);
        printf("IRA %.2f\n------------------\n", p[i].IRA);
    }
    
}

void liberar(Aluno *p){
    free(p);
}