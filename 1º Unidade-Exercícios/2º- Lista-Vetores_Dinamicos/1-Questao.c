#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>               //Importando a biblioteca "string.h" para conseguir manipular as strings e fazer
                                  //comparações entre elas.  
int main(){
    setlocale(LC_ALL,"Portuguese");

    int i = 0, total = 0, test = 0, h = 0, m = 0;
    char **per_1 = (char**) malloc(1 * sizeof(char*));          //Alocando memória para cada resposta das perguntas.
    char **per_2 = (char**) malloc(1 * sizeof(char*));          //Para cada nova pessoa entrevistada um novo ponteiro de resposta será criado.
                                                                

    if(per_1 == NULL || per_2 == NULL){
        printf("Erro na alocação de memória!");                 //Verificando se alocação de memória ocorreu bem.
        free(per_1); free(per_2);
        exit(1);
    }

    do{                                                         //Iniciando um laço de repetição com o "do while".                                                              

        printf("----------------------------\nEntrevistados: %d pessoas\n", total);
        printf("----------------------------\n[ 1 ] Adicionar Entrevistado\n[ 2 ] ");          //Menu de opções.
        printf("Encerrar Pesquisa\n[ 3 ] Sair\n----------------------------\nOPÇÃO: ");
        scanf("%d", &test);                                                                    //Lendo a opção que o usuário digitou.
        fflush(stdin);

        switch (test){                                         //Fazendo um "switch" na variável "test" para saber qual bloco de comando será executado.
            case 1:
                per_1 = (char**) realloc(per_1, (1 + i) * sizeof(char*));        //Opção 1: Realocando memória para criar um novo ponteiro   
                per_2 = (char**) realloc(per_2, (1 + i) * sizeof(char*));        //para cada resposta.

                if(per_1 == NULL || per_2 == NULL){
                    printf("Erro na alocação de memória!");                     
                    free(per_1); free(per_2);                                    //Verificando se a alocação de memória ocorreu bem.   
                    exit(1);
                }

                per_1[i] = (char*) malloc(1 * sizeof(char));         //Alocando memória para conseguir armazenar as respostas               
                per_2[i] = (char*) malloc(1 * sizeof(char));         //das pessoas dentro de cada ponteiro criado.  

                if(per_1[i] == NULL || per_2[i] == NULL ){;
                    printf("Erro na alocação de memória!");
                    free(per_1); free(per_2);                        //Verificando se a alocação de memória ocorreu bem.   
                    exit(1);
                }

                printf("Perguntas:\n1º Qual é o seu sexo? [M/F]\n>>");      //Fazendo as 2 perguntas e armazenando dentro de cada vetor
                scanf(" %1s", per_1[i]);                                    //de resposta. OBS: lendo apenas a 1º letra que o usuário digitar
                fflush(stdin);                                              //usando "%1s".
                printf("2º Você gostou do novo produto? [S/N]\n>>");        //Limpando o "buffer do teclado" após cada "scanf" com a função "fflush(stdin)".
                scanf(" %1s", per_2[i]);                                    
                fflush(stdin);

                if(strcmp(per_1[i], "F") == 0 && strcmp(per_2[i], "S") == 0){         //Verificando se as pessoas do sexo feminino gostaram do novo produto.
                    m++;                                                              //Se sim, é incrementado em +1 a variável "m". 
                }

                if(strcmp(per_1[i], "M") == 0 && strcmp(per_2[i], "N") == 0){         //Verificando se as pessoas do sexo masculino não gostaram do novo produto.      
                    h++;                                                              //Se sim, é incrementado em +1 a variável "h".  
                }

                i++;                //Após responder as 2 perguntas, as variáveis "i" e "total" são incrementadas em +1
                total++;            //para que na próxima interação seja alocado os novos vetores de resposta de cada nova pessoa.

                break;
            case 2:
                printf("Pessoas do sexo feminino que gostaram do produto: %.1f%%\n", (m * 100.0 / total));          //Opção 2: Imprimir o percentual de pessoas sexo feminino que gostaram do produto e 
                printf("Pessoas do sexo masculino que não gostaram do produto: %.1f%%\n", (h * 100.0 / total));     //das pessoas do sexo masculino que não gostaram do produto. 

                break;
            case 3:
                printf("Saindo...");            //Opção 3: Caso o usuário digite 3, o programa será encerrado.
                exit(0);

                break;
            default:
                printf("Opção Inválida!\n");    //Caso o usuário digitar uma opção diferente do menu, será impresso
                                                //uma mensagem de "Opção Inválida!" e será reiniciado o laço de repetição.
                break;
        }   

    } while (test != 3);

    for (i = 0; i < total; i++){                
        free(per_1[i]);                         //Após o termino do laço de repetição, são liberados da memória os vetores
        free(per_2[i]);                         //que armazenam as respostas de cada pessoa.
    }

    free(per_1);        //Liberando a memória dos vetores de ponteiros criados para 
    free(per_2);        //cada resposta.

    return 0;
}