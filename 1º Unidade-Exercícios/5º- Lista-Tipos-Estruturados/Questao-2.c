#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

const int MAX=2;

typedef struct disciplina{
    int matricula;
    char nome[80];
    char turma[10];
    float notas[3];
    float media;

} Disciplina;

void add_alunos(Disciplina *p, int t){
    int i;
    float media = 0;

    printf("=-=-=-=-=-=-=-=\n");
    printf("Nome do aluno: ");
    fgets(p->nome, 80, stdin);
    fflush(stdin);
    printf("Matricula: ");
    scanf("%d", &p->matricula);
    fflush(stdin);
    printf("Turma: ");
    fgets(p->turma, 10, stdin);
    printf("Notas:\n");

    for(i = 0; i < 3; i++){
        printf("%dº nota: ", i + 1);
        scanf(" %f", &p->notas[i]);
        media += p->notas[i];
    }
    p->media = media / 3;

}

void lanca_notas(Disciplina **p, int t){
    int i, j;

    for ( i = 0; i < t; i++){
        printf("Nome: %s", p[i]->nome);
        printf("Turma: %s", p[i]->turma);

        for ( j = 0; j < 3; j++){
            printf("%dº nota: %.1f\n", j + 1, p[i]->notas[j]);
        }
    
        printf("Média: %.1f\n", p[i]->media);
        printf("--------------------\n");
    }
    system("pause");
}

void imprimir(Disciplina **p, int t){
    int i;

    for ( i = 0; i < t; i++){
        printf("Nome: %s", p[i]->nome);
        printf("Matricula: %d\n", p[i]->matricula);
        printf("Turma: %s", p[i]->turma);
        printf("Média: %.2f\n", p[i]->media);
        printf("--------------------\n");
    }
    system("pause");
}

void turma_imprimir(Disciplina **p, int t){
    int i, j;
    char turma[20];

    printf("Qual a turma? ");
    fgets(turma, 20, stdin);

    for ( i = 0; i < t; i++){
        if(strcmp(turma, p[i]->turma) == 0){

            printf("Nome: %s", p[i]->nome);
            printf("Matricula: %d\n", p[i]->matricula);

            for ( j = 0; j < 3; j++){
                printf("%dº nota: %.1f\n", j + 1, p[i]->notas[j]);
            }
            
            printf("Média: %.2f\n", p[i]->media);
            printf("--------------------\n");
        }
    }
    system("pause");
}

void aprovados(Disciplina **p, int t){
    int i;

    for ( i = 0; i < t; i++){
        if(p[i]->media >= 7.0){
            printf("Nome: %s", p[i]->nome);
            printf("Matricula: %d\n", p[i]->matricula);
            printf("Turma: %s", p[i]->turma);
            printf("Média: %.2f\n", p[i]->media);
            printf("--------------------\n");
        }
    }
    system("pause");
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    int i = 0, tam = 0;
    char dis[30];

    Disciplina **alunos = (Disciplina**) malloc(sizeof(Disciplina*));
    
    if (alunos == NULL){
        printf("Erro na alocacao!");
        exit(1);
    }

    printf("Qual é o nome da disciplina? ");
    fgets(dis, 30, stdin);
    fflush(stdin);

    while (i != 999){
        system("cls");
        printf("Disciplina: %s", dis);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("[1] Adicionar aluno\n[2] Mostrar notas dos alunos\n[3] Mostrar alunos da disciplina\n[4] Mostrar alunos de uma turma\n[5] Mostrar alunos aprovados\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

        printf("Opção [999 se encerra] >> ");
        scanf("%d", &i);
        fflush(stdin);
        system("cls");

        switch (i){
            
        case 1:
            if (tam < MAX){
                alunos[tam] = (Disciplina*) malloc(sizeof(Disciplina));

                if (alunos[tam] == NULL){
                    printf("Erro na alocacao!");
                    exit(1);
                }
        
                add_alunos(alunos[tam], tam);
                tam ++;
            }else{
                printf("Tamanho máximo alcançado!\n");
                system("pause");
            }
            break;
        case 2:
            lanca_notas(alunos, tam);
            break;
        case 3:
            imprimir(alunos, tam);
            break;
        case 4:
            turma_imprimir(alunos, tam);
            break;
        case 5:
            aprovados(alunos, tam);
            break;
        }
    }

    for (i = 0; i < tam; i++) {
        free(alunos[i]);
    }

    free(alunos);

    return 0;
}