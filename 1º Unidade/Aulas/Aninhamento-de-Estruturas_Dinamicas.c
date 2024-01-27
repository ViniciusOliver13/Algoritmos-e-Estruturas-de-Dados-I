#include <stdio.h>
#include <stdlib.h>

/*Exemplo de Aninhamento de Estruturas Dinâmicas*/

typedef struct disciplina{
    char nome[20];
    float nota;
    int codigo;
} Disciplina;

typedef struct aluno{
    char nome[20];
    int idade, matricula;
    Disciplina *materias;    
} Aluno;

int main(){
    
    Aluno *aluno = (Aluno*)malloc(sizeof(Aluno));            //Declarando uma variável do tipo "Aluno".
    int i;

    if(aluno == NULL){
        exit(1);
    }

    //Alocando memória para o vetor de disciplinas
    aluno->materias = (Disciplina*)malloc(2 * sizeof(Disciplina));

    if(aluno->materias == NULL){
        exit(1);
    }

    printf("nome: %s\n",  aluno->nome);
    printf("idade: %d\nmatricula: %d", aluno->idade, aluno->matricula);

    //Cadastro de disciplinas
    for ( i = 0; i < 2; i++){
        printf("Cadastro da Disciplina %d:", i + 1);
        scanf(" %[^\n]", aluno->materias[i].nome);
        scanf("%d", &aluno->materias[i].codigo);
        scanf("%f", &aluno->materias[i].nota);
    }

    return 0;
}