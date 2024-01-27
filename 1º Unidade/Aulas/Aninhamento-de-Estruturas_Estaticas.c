#include <stdio.h>
#include <stdlib.h>

/*Exemplo de Aninhamento de Estruturas Estáticas*/

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno{
    char nome[20];
    int idade, matricula;
    Disciplina materias[7];  // Aninhamento de Estruturas do tipo "Disciplina" na estrutura "aluno".
} Aluno;

int main(){
    
    Aluno aluno;            // Declarando uma variável do tipo "Aluno".
    
    aluno.idade = 15;
    aluno.matricula = 2023012;
    aluno.materias[0].codigo = 98078;

    printf("%d, %d, %d \n", aluno.idade, aluno.matricula, aluno.materias[0].codigo);


    return 0;
}