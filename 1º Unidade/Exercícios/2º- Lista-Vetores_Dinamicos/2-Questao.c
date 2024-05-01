#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>               //Importando a biblioteca "string.h" para conseguir manipular as strings e fazer
                                  //compara��es entre elas.
int main(){
    setlocale(LC_ALL,"Portuguese");

    int cont, i = 0, questoes = 0;
    float percent = 0.0, aprov = 0.0, notas[10];      //Declarando todas as vari�veis, vetores e ponteiros que ser�o usados.
    char **gabarito = NULL, *respostas = NULL;

    printf("================\nG A B A R I T O\n================\n");
    printf("Digite o n�mero de Quest�es: ");
    scanf("%d", &questoes);                           //Pedindo para o usu�rio informar a quantidade de quest�es dessa prova.   
    fflush(stdin);                                    //Limpando o "buffer do teclado" ap�s cada "scanf" com a fun��o "fflush(stdin)".  

    gabarito = (char**) malloc(questoes * sizeof(char*));       //Alocando mem�ria de acordo com a quantidade de quest�es informadas.
    respostas = (char*) malloc(100 * sizeof(char));             //Ao alocar mem�ria para cada quest�o, � criado um ponteiro do tipo "char".
                                                                //Alocando mem�ria para uma string "resposta" de tamanho 100.
    if(gabarito == NULL || respostas == NULL ){
        printf("Erro na aloca��o!");                            //Verificando se a aloca��o de mem�ria ocorreu bem.
        free(gabarito);  free(respostas);
        exit(1);
    }

    for ( i = 0; i < questoes; i++){
            gabarito[i] = (char*) malloc(100 * sizeof(char));   //Alocando mem�ria para o ponteiro de "gabarito" de cada nova quest�o.

            printf("Resposta da %d� pergunta: ", i + 1);
            fgets(gabarito[i], 100, stdin);                     //Lendo o gabarito da quest�o com a fun��o "fgets()".    

            gabarito[i] = (char*) realloc(gabarito[i], (strlen(gabarito[i]) + 1) * sizeof(char));      //Realocando a mem�ria de acordo com o tamanho da resposta.

            if(gabarito[i] == NULL){
                printf("Erro na aloca��o!");                    
                                                                  
                for ( i = 0; i < questoes; i++){                //Verificando se a aloca��o de mem�ria ocorreu bem.
                    free(gabarito[i]);                          //Se n�o, � feita a libera��o da mem�ria alocada para cada quest�o do gabarito
                }                                               //e dos ponteiros de "gabarito".

                free(gabarito);
                exit(1);                                        //Encerrando a execu��o do programa com a fun��o "exit()".    
            }
        }

    printf("Gabarito terminado!!\n");
    system("pause");                                //Imformando que o gabarito foi completado.
    system("cls");                                  //Usando a fun��o "system("cls")" para limpar a tela.

    for ( i = 0; i < 10; i++){                              //Iniciando o la�o de repeti��o "for()" at� 10 que � n�mero de alunos informados.
        printf("Respostas do %d aluno:\n", i + 1);

        for ( cont = 0; cont < questoes; cont++){           //Iniciando o la�o de repeti��o "for()" at� o n�mero de quest�es informadas.
            
            printf("%d� Quest�o >> ", cont + 1);            //Lendo a resposta de cada aluno com a fun��o "fgets()".
            fgets(respostas, 100, stdin);                   

            if(strcmp(respostas, gabarito[cont]) == 0){     //Comparando a resposta com a do gabarito cadastrado, usando a fun��o "strcmp".
                aprov += 10.0 / questoes;                   //Se acertou, a nota de cada cada quest�o � armazenada em "aprov".

                printf("Acertou!\n");                       //Imprimindo uma mensagem caso o aluno tenha acertado a quest�o.
            }else{
                printf("Errou!\n");                         //Imprimindo uma mensagem caso o aluno tenha errado a quest�o.
            }
            
        }

        notas[i] = aprov;                  //Vetor "notas[i]" recebe a nota do aluno de �ndice do valor de "i".

        if(aprov >= 6.0){
            printf("Aluno passou!\n");     //Imprimindo uma mensagem caso o aluno tenha conseguido uma nota maior ou igual a 6.0.
            percent++;                     //Vari�vel "percent" recebe +1. Usanda para saber o percentual de aprova��o da turma.
        }

        aprov = 0.0;                       //O valor da vari�vel "aprov" � reiniciado para 0.0. Assim, ela s� armazena a nota de um
                                           //aluno para cada novo la�o de repeti��o.
    }

    system("pause");
    system("cls");                  

    for ( i = 0; i < 10; i++){
        printf("Notas:\n%d� aluno >> %.1f\n", i + 1, notas[i]);             //Imprimindo as notas de cada aluno.
    }

    printf("TAXA DE APROVA��O DA TURMA: %.2f%%", percent * 100 / 10);       //Mostrando a percentual de aprova��o da turma.

    for ( i = 0; i < questoes; i++){                //Liberando da mem�ria as strings criadas para armazenar o gabarito.
        free(gabarito[i]);
    }

    free(gabarito);                                 //Liberando da mem�ria os ponteiros de "gabarito" e 
    free(respostas);                                //a string "resposta".

    return 0;
}