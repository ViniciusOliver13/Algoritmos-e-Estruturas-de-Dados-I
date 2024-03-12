#include <stdio.h>
#include <stdlib.h>
#include "disciplina.c"
#include "aluno.c"


int main(){
    char nome[50];
    int i,j, cod, tam = 0, tam_aluno = 0, opc = 0;
    char test = 'S';
    Disciplina **p = NULL;
    Aluno **aluno = NULL;

    do{
        printf("[1] Adicionar disciplina\n[2] Excluir disciplina\n[3] Adicionar aluno\n[4] Matricular aluno\nOpcao >> ");
        scanf("%d", &opc);

        switch (opc){
            case 1:
                printf("Nome da disciplina: ");
                scanf(" %[^\n]", nome);
                printf("Codigo da disciplina: ");
                scanf("%d", &cod);

                p = realloc(p, (tam + 1) * sizeof(Disciplina*));

                if (p == NULL){
                    printf("Erro ao alocar memoria.\n");
                    exit(1);
                }

                p[tam] = cria_disciplina(nome, cod);

                if (p[tam] == NULL){
                    printf("Erro ao alocar memoria.\n");
                    exit(1);
                }

                tam++;
            break;

            case 2:
                printf("Informe o codigo da disciplina: ");
                scanf("%d", &cod);

                for (i = 0; i < tam; i++){
                    if (p[i]->codigo == cod){
                        exclui_disciplina(p[i]);
                        p[i] = p[tam - 1];
                        tam--;
                        printf("A disciplina foi excluida com sucesso!\n");
                    }
                }
            break;

            case 3:
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nome);
                printf("Informe a matricula: ");
                scanf("%d", &cod);

                aluno = realloc(aluno, (tam_aluno + 1) * sizeof(Aluno*));
                
                if (aluno == NULL){
                    printf("Erro ao alocar memoria.\n");
                    exit(1);
                }

                aluno[tam_aluno] = cria_aluno(nome, cod);

                if (aluno[tam_aluno] == NULL){
                    printf("Erro ao alocar memoria.\n");
                    exit(1);
                }
                
                tam_aluno++;
            break;
            
            case 4:
                printf("Informe a matricula do aluno: ");
                scanf("%d", &cod);

                for(i = 0; i < tam_aluno; i++){
                    if(cod == aluno[i]->matricula);
                        printf("Qual disciplina? Informe o codigo dela: ");
                        scanf("%d", &cod);
                        for ( j = 0; j < tam; j++){
                            if(cod == p[j]->codigo){
                                matricula_disciplina(aluno[i], p[j]);
                            }
                        }
                }
            break;
            
            default:
            break;
        }
        
        printf("Continuar? [S/N]");
        scanf(" %c", &test);

    }while(test == 'S' || test == 's');

    exibe_alunos_matriculados(aluno, tam_aluno);

    return 0;
}
