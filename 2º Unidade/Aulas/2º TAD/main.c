#include <stdio.h>
#include <stdlib.h> 
#include "aluno.c"
/* TAD : Tipo Abstrato de Dados */
/* TAD : um novo tipo (struct) + cojunto de operações */

int main(){

    printf("\033[1mCastrado de alunos\n=-=-=-=-=-=-=-=-=-=-=-=\n");

    Aluno *aluno = matricular_alunos();

    liberar(aluno);

    return 0;
}
