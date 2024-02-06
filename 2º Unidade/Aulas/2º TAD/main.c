#include <stdio.h>
#include <stdlib.h> 
#include "aluno.h"
/* TAD : Tipo Abstrato de Dados */
/* TAD : um novo tipo (struct) + cojunto de operações */

int main(){

    Aluno *aluno = NULL;
    int tamanho = 0;

    printf("\033[1mCastrado de alunos\n=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("Qual a quantidade de alunos? ");
    scanf("%d", &tamanho);

    aluno = matricular_alunos(tamanho);
    
    imprimir(aluno, tamanho);

    liberar(aluno);

    return 0;
}