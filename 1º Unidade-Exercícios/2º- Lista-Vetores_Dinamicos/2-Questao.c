#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>               //Importando a biblioteca "string.h" para conseguir manipular as strings e fazer
                                  //comparações entre elas.
int main(){
    setlocale(LC_ALL,"Portuguese");

    int cont, i = 0, questoes = 0;
    float percent = 0.0, aprov = 0.0, notas[10];      //Declarando todas as variáveis, vetores e ponteiros que serão usados.
    char **gabarito = NULL, *respostas = NULL;

    printf("================\nG A B A R I T O\n================\n");
    printf("Digite o número de Questões: ");
    scanf("%d", &questoes);                           //Pedindo para o usuário informar a quantidade de questões dessa prova.   
    fflush(stdin);                                    //Limpando o "buffer do teclado" após cada "scanf" com a função "fflush(stdin)".  

    gabarito = (char**) malloc(questoes * sizeof(char*));       //Alocando memória de acordo com a quantidade de questões informadas.
    respostas = (char*) malloc(100 * sizeof(char));             //Ao alocar memória para cada questão, é criado um ponteiro do tipo "char".
                                                                //Alocando memória para uma string "resposta" de tamanho 100.
    if(gabarito == NULL || respostas == NULL ){
        printf("Erro na alocação!");                            //Verificando se a alocação de memória ocorreu bem.
        free(gabarito);  free(respostas);
        exit(1);
    }

    for ( i = 0; i < questoes; i++){
            gabarito[i] = (char*) malloc(100 * sizeof(char));   //Alocando memória para o ponteiro de "gabarito" de cada nova questão.

            printf("Resposta da %dº pergunta: ", i + 1);
            fgets(gabarito[i], 100, stdin);                     //Lendo o gabarito da questão com a função "fgets()".    

            gabarito[i] = (char*) realloc(gabarito[i], (strlen(gabarito[i]) + 1) * sizeof(char));      //Realocando a memória de acordo com o tamanho da resposta.

            if(gabarito[i] == NULL){
                printf("Erro na alocação!");                    
                                                                  
                for ( i = 0; i < questoes; i++){                //Verificando se a alocação de memória ocorreu bem.
                    free(gabarito[i]);                          //Se não, é feita a liberação da memória alocada para cada questão do gabarito
                }                                               //e dos ponteiros de "gabarito".

                free(gabarito);
                exit(1);                                        //Encerrando a execução do programa com a função "exit()".    
            }
        }

    printf("Gabarito terminado!!\n");
    system("pause");                                //Imformando que o gabarito foi completado.
    system("cls");                                  //Usando a função "system("cls")" para limpar a tela.

    for ( i = 0; i < 10; i++){                              //Iniciando o laço de repetição "for()" até 10 que é número de alunos informados.
        printf("Respostas do %d aluno:\n", i + 1);

        for ( cont = 0; cont < questoes; cont++){           //Iniciando o laço de repetição "for()" até o número de questões informadas.
            
            printf("%dº Questão >> ", cont + 1);            //Lendo a resposta de cada aluno com a função "fgets()".
            fgets(respostas, 100, stdin);                   

            if(strcmp(respostas, gabarito[cont]) == 0){     //Comparando a resposta com a do gabarito cadastrado, usando a função "strcmp".
                aprov += 10.0 / questoes;                   //Se acertou, a nota de cada cada questão é armazenada em "aprov".

                printf("Acertou!\n");                       //Imprimindo uma mensagem caso o aluno tenha acertado a questão.
            }else{
                printf("Errou!\n");                         //Imprimindo uma mensagem caso o aluno tenha errado a questão.
            }
            
        }

        notas[i] = aprov;                  //Vetor "notas[i]" recebe a nota do aluno de índice do valor de "i".

        if(aprov >= 6.0){
            printf("Aluno passou!\n");     //Imprimindo uma mensagem caso o aluno tenha conseguido uma nota maior ou igual a 6.0.
            percent++;                     //Variável "percent" recebe +1. Usanda para saber o percentual de aprovação da turma.
        }

        aprov = 0.0;                       //O valor da variável "aprov" é reiniciado para 0.0. Assim, ela só armazena a nota de um
                                           //aluno para cada novo laço de repetição.
    }

    system("pause");
    system("cls");                  

    for ( i = 0; i < 10; i++){
        printf("Notas:\n%dº aluno >> %.1f\n", i + 1, notas[i]);             //Imprimindo as notas de cada aluno.
    }

    printf("TAXA DE APROVAÇÃO DA TURMA: %.2f%%", percent * 100 / 10);       //Mostrando a percentual de aprovação da turma.

    for ( i = 0; i < questoes; i++){                //Liberando da memória as strings criadas para armazenar o gabarito.
        free(gabarito[i]);
    }

    free(gabarito);                                 //Liberando da memória os ponteiros de "gabarito" e 
    free(respostas);                                //a string "resposta".

    return 0;
}