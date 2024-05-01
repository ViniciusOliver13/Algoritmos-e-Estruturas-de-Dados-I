#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disciplina.h"

struct disciplina{
    char nome[50];
    int codigo;
};

Disciplina *cria_disciplina(char nome[], int codigo){
    Disciplina *p = (Disciplina*)malloc(sizeof(Disciplina));

    if(p == NULL){
        printf("Sem memoria!");
        exit(1);
    }

    strcpy(p->nome, nome);
    p->codigo = codigo;

    return p;
}

void exclui_disciplina(Disciplina *disciplina){
        free(disciplina);
}

// Função para exibir as disciplinas cadastradas
void exibe_disciplinas(Disciplina** disciplinas, int num_disciplinas) {
    int i;
    printf("Disciplinas cadastradas:\n");
    for (i = 0; i < num_disciplinas; i++) {
        printf("Disciplina %d:\n", i+1);
        printf("Nome: %s\n", disciplinas[i]->nome);
        printf("Codigo: %d\n", disciplinas[i]->codigo);
        printf("\n");
    }
}
