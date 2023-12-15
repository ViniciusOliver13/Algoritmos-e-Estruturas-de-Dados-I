#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct pessoa{
    char nome[50];              //Declarando a struct "pessoa".
    int documento, idade;
} pessoa;

void preencher(pessoa *point, int tam){         //Função para preencher todos os campos da struct "pessoa".
    printf("Digite seu nome: ");
    scanf(" %[^\n]", point[tam].nome);
    printf("Digite a idade: ");
    scanf("%d", &point[tam].idade);
    printf("Digite o numero do documento: ");
    scanf("%d", &point[tam].documento);
}
void imprimir(pessoa *point, int tam){
    int  i;                                     //Função para imprimir todas as pessoas cadastradas.

    for ( i = 0; i < tam; i++){
        printf("%dº Pessoa:\nNome: %s\nIdade: %d\n", i + 1, point[i].nome, point[i].idade);
        printf("Número do documento: %d\n",point[i].documento);
        printf("================\n");
    }
    
}

void atualizarIdade(pessoa *point, int tam){
    int x = 0, i;
    char test;                                          //Função para alterar a idade de uma pessoa.                                 

    printf("Deseja alterar a idade de alguma pessoa: ");
    scanf(" %c", &test);

    if(test == 'S' || test == 's'){

        for ( i = 0; i < tam; i++){
            printf("Nome: %s\nNúmero do documento: %d\n\n", point[i].nome, point[i].documento);
        }

        printf("Informe o número do documento: ");      //Pedindo ao usuário o número do documento.
        scanf("%d", &i);

        for (x = 0; x < tam; x++) {
            if ( i == point[x].documento) {
                printf("Nome: %s\nIdade atual: %d\nNova idade: ", point[x].nome, point[x].idade);
                scanf("%d", &point[x].idade);
                printf("\nIdade alterada com sucesso!");
                break;
            }
        }   
    }
    system("cls");
}

void maisVelhoMaisnovo(pessoa *point, int tam){     //Função para saber quem é a pessoa mais velha e a mais nova.
    int pos1, pos2, velho = 0, novo = 0, i = 0;
    novo = 200;     
    
    for (i = 0; i < tam; i++){
        if (novo > point[i].idade){
            novo = point[i].idade;
            pos2 = i;
        }
        if (velho < point[i].idade){
            velho = point[i].idade;
            pos1 = i;
        }
    }
    printf("Pessoa mais velha:\nNome: %s\nIdade: %d\n\n", point[pos1].nome, point[pos1].idade);
    printf("Pessoa mais nova:\nNome: %s\nIdade: %d\n\n", point[pos2].nome, point[pos2].idade);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int tam = 0;
    char test;
    pessoa *p = (pessoa*) malloc(sizeof(pessoa));   //Alocando memória para a variável "p".

    if(p == NULL){  
        printf("erro na alocacao");                 //Verificando se a alocação ocorreu bem.
        exit(1);
    }

    do{

        printf("Adicionar pessoa? ");               //Iniciando o laço de repetição "do while()" perguntando se o usuário quer adicionar mais pessoas.
        scanf(" %c", &test);

        if(test == 'S' || test == 's'){

            p = (pessoa*)realloc(p, (tam + 1) * sizeof(pessoa));        //Realocando memória conforme novas pessoas são cadastradas.

            if(p == NULL){                          //Verificando se a realocação ocorreu bem.
                printf("Erro na realocacao");       
                exit(0);
            }

            preencher(p, tam);           //Chamada para a função "preencher".         

            tam++;                       //Incremento de +1 a cada nova pessoa adicionada.

            atualizarIdade(p, tam);      //Chamada para a função "atualizarIdade".   
        }else{
            system("pause");
            break;
        }

    }while(test != 'N' || test != 'n');

    system("cls");
    imprimir(p, tam);               //Chamadas para as funções "imprimir" e "maisVelhoMaisnovo".
    maisVelhoMaisnovo(p, tam);

    free(p);                        //Liberando a memória ao final da execução.

    return 0;
}