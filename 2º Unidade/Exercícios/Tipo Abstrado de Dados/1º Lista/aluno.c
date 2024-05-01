#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char nome[100];
    int matricula;
    Disciplina *disciplina[10];
    int num_disciplina;
};

Aluno *cria_aluno(char nome[], int matricula){
    Aluno *p = (Aluno*)malloc(sizeof(Aluno));

    if(p == NULL){
        printf("Sem memoria!");
        exit(1);
    }

    strcpy(p->nome, nome);
    p->matricula = matricula;
    p->num_disciplina = 0;

    return p;
}

void matricula_disciplina(Aluno *aluno, Disciplina *disciplina){
    int MAX = 10;

    if (aluno->num_disciplina < MAX) {
        aluno->disciplina[aluno->num_disciplina] = disciplina;
        aluno->num_disciplina += 1;
    }else{
        printf("O aluno ja esta matriculado em muitas disciplinas!\n");
    }
}
/*
void exclui_aluno(Aluno *aluno){
    
}
*/

void exibe_alunos_matriculados(Aluno** alunos, int num_alunos) {
    int i,j;
    
    printf("Alunos matriculados:\n");
    for (i = 0; i < num_alunos; i++) {
        printf("Aluno %d:\n", i+1);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Matricula: %d\n", alunos[i]->matricula);
        printf("Disciplinas matriculadas:\n");
        for (j = 0; j < alunos[i]->num_disciplina; j++) {
            printf("- %s\n", alunos[i]->disciplina[j]->nome);
        }
        printf("\n");
    }
}
