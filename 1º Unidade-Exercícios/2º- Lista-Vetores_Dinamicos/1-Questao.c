#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>               //Importando a biblioteca "string.h" para conseguir manipular as strings e fazer
                                  //compara��es entre elas.  
int main(){
    setlocale(LC_ALL,"Portuguese");

    int i = 0, total = 0, test = 0, h = 0, m = 0;
    char **per_1 = (char**) malloc(1 * sizeof(char*));          //Alocando mem�ria para cada resposta das perguntas.
    char **per_2 = (char**) malloc(1 * sizeof(char*));          //Para cada nova pessoa entrevistada um novo ponteiro de resposta ser� criado.
                                                                

    if(per_1 == NULL || per_2 == NULL){
        printf("Erro na aloca��o de mem�ria!");                 //Verificando se aloca��o de mem�ria ocorreu bem.
        free(per_1); free(per_2);
        exit(1);
    }

    do{                                                         //Iniciando um la�o de repeti��o com o "do while".                                                              

        printf("----------------------------\nEntrevistados: %d pessoas\n", total);
        printf("----------------------------\n[ 1 ] Adicionar Entrevistado\n[ 2 ] ");          //Menu de op��es.
        printf("Encerrar Pesquisa\n[ 3 ] Sair\n----------------------------\nOP��O: ");
        scanf("%d", &test);                                                                    //Lendo a op��o que o usu�rio digitou.
        fflush(stdin);

        switch (test){                                         //Fazendo um "switch" na vari�vel "test" para saber qual bloco de comando ser� executado.
            case 1:
                per_1 = (char**) realloc(per_1, (1 + i) * sizeof(char*));        //Op��o 1: Realocando mem�ria para criar um novo ponteiro   
                per_2 = (char**) realloc(per_2, (1 + i) * sizeof(char*));        //para cada resposta.

                if(per_1 == NULL || per_2 == NULL){
                    printf("Erro na aloca��o de mem�ria!");                     
                    free(per_1); free(per_2);                                    //Verificando se a aloca��o de mem�ria ocorreu bem.   
                    exit(1);
                }

                per_1[i] = (char*) malloc(1 * sizeof(char));         //Alocando mem�ria para conseguir armazenar as respostas               
                per_2[i] = (char*) malloc(1 * sizeof(char));         //das pessoas dentro de cada ponteiro criado.  

                if(per_1[i] == NULL || per_2[i] == NULL ){;
                    printf("Erro na aloca��o de mem�ria!");
                    free(per_1); free(per_2);                        //Verificando se a aloca��o de mem�ria ocorreu bem.   
                    exit(1);
                }

                printf("Perguntas:\n1� Qual � o seu sexo? [M/F]\n>>");      //Fazendo as 2 perguntas e armazenando dentro de cada vetor
                scanf(" %1s", per_1[i]);                                    //de resposta. OBS: lendo apenas a 1� letra que o usu�rio digitar
                fflush(stdin);                                              //usando "%1s".
                printf("2� Voc� gostou do novo produto? [S/N]\n>>");        //Limpando o "buffer do teclado" ap�s cada "scanf" com a fun��o "fflush(stdin)".
                scanf(" %1s", per_2[i]);                                    
                fflush(stdin);

                if(strcmp(per_1[i], "F") == 0 && strcmp(per_2[i], "S") == 0){         //Verificando se as pessoas do sexo feminino gostaram do novo produto.
                    m++;                                                              //Se sim, � incrementado em +1 a vari�vel "m". 
                }

                if(strcmp(per_1[i], "M") == 0 && strcmp(per_2[i], "N") == 0){         //Verificando se as pessoas do sexo masculino n�o gostaram do novo produto.      
                    h++;                                                              //Se sim, � incrementado em +1 a vari�vel "h".  
                }

                i++;                //Ap�s responder as 2 perguntas, as vari�veis "i" e "total" s�o incrementadas em +1
                total++;            //para que na pr�xima intera��o seja alocado os novos vetores de resposta de cada nova pessoa.

                break;
            case 2:
                printf("Pessoas do sexo feminino que gostaram do produto: %.1f%%\n", (m * 100.0 / total));          //Op��o 2: Imprimir o percentual de pessoas sexo feminino que gostaram do produto e 
                printf("Pessoas do sexo masculino que n�o gostaram do produto: %.1f%%\n", (h * 100.0 / total));     //das pessoas do sexo masculino que n�o gostaram do produto. 

                break;
            case 3:
                printf("Saindo...");            //Op��o 3: Caso o usu�rio digite 3, o programa ser� encerrado.
                exit(0);

                break;
            default:
                printf("Op��o Inv�lida!\n");    //Caso o usu�rio digitar uma op��o diferente do menu, ser� impresso
                                                //uma mensagem de "Op��o Inv�lida!" e ser� reiniciado o la�o de repeti��o.
                break;
        }   

    } while (test != 3);

    for (i = 0; i < total; i++){                
        free(per_1[i]);                         //Ap�s o termino do la�o de repeti��o, s�o liberados da mem�ria os vetores
        free(per_2[i]);                         //que armazenam as respostas de cada pessoa.
    }

    free(per_1);        //Liberando a mem�ria dos vetores de ponteiros criados para 
    free(per_2);        //cada resposta.

    return 0;
}