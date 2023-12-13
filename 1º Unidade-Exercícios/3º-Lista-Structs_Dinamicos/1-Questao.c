#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct funcionario{                     //Declarando a struct "funcionario".
    char nome[50], cargo[30];
    int idade, identificador;
    float salario;
} funcionario;

void preencher(funcionario *point, int tam){    //Fun��o para preencher o vetor de structs "funcionario".

    printf("Nome: ");
    scanf(" %[^\n]", point[tam].nome);
    printf("Idade: ");
    scanf("%d", &point[tam].idade);
    printf("Cargo: ");
    scanf(" %[^\n]", point[tam].cargo);
    printf("Sal�rio: R$");
    scanf("%f", &point[tam].salario);
    printf("Identificador: " );
    scanf("%d", &point[tam].identificador);
}

void alterarSal(funcionario *point, int tam){   //Fun��o para alterar o sal�rio de algum funcion�rio cadastrado.
    char test;
    int i;

    printf("Deseja mudar o sal�rio de algum funcion�rio?");
    scanf(" %c", &test);

    if(test == 'S' || test == 's'){
        system("cls");

        for(i = 0; i < tam; i++){
            printf("Nome do funcion�rio: %s\nN�mero do sistema: %d\n\n", point[i].nome, i);
        }

        printf("Digite o n�mero de sistema: ");
        scanf("%d", &i);
        printf("Sal�rio atual desse funcion�rio: R$%.2f\nQual � o novo sal�rio? R$", point[i].salario);
        scanf(" %f", &point[i].salario);
        printf("Sal�rio modificado com sucesso!!\n");
    }
}
void maiorMenorSal(funcionario *point, int tam){    //Fun��o para saber o funcion�rio com o maior e o menor sal�rio e tamb�m seu cargo.
    int maior, menor, i = 0;
    float sal_menor = 0, sal_maior = 0;
    sal_menor = point[i].salario;

    for ( i = 0; i < tam; i++){
        if(sal_maior < point[i].salario){
            sal_maior = point[i].salario;
            maior = i;
        }else if (sal_menor > point[i].salario){
            sal_menor = point[i].salario;
            menor = i;
        }
    }
    printf("\n=====================\nFuncion�rio com o maior sal�rio:\n");
    printf("Nome: %s\nCargo: %s\nSal�rio: R$%.2f\n", point[maior].nome, point[maior].cargo, point[maior].salario);      //Imprimindo o nome, cargo, sal�rios desses funcion�rios
    printf("=====================\nFuncion�rio com o menor sal�rio:\n");
    printf("Nome: %s\nCargo: %s\nSal�rio: R$%.2f\n=====================", point[menor].nome, point[menor].cargo, point[menor].salario);
}

void imprimir(funcionario *point, int tam){     //Fun��o para imprimir o nome, idade, cargo, sal�rio e identificador de todos os funcion�rios cadastrados.  
    int i;

    for ( i = 0; i < tam; i++){
        printf("---------------------\n");
        printf("Nome: %s\n", point[i].nome); 
        printf("Idade: %d\n", point[i].idade);   
        printf("Cargo: %s\n", point[i].cargo);
        printf("Sal�rio: %.2f\n", point[i].salario);
        printf("Identificador: %d\n", point[i].identificador); 
    }
    printf("---------------------");
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    int tam = 0;
    char test; 
    funcionario *p = (funcionario*) malloc(sizeof(funcionario));    //Alocando mem�ria para a vari�vel "p"do tamanho do tipo "funcionario".

    if(p == NULL){
        printf("\nErro na aloca��o!");      //Verificando se a aloca��o de mem�ria ocorreu bem.
        exit(1);    
    }

    do{                                     //Iniciando o la�o de repeti��o "do while()" para perguntar ao usu�rio se ele quer adicionar um funcion�rio.

        printf("Adicionar funcionario? ");      
        scanf(" %c", &test);

        if(test == 'S' || test == 's'){
            
            system("cls");

            p = (funcionario*) realloc(p, (tam + 1) * sizeof(funcionario));     //Realocando a mem�ria conforme novos funcion�rios s�o adicionados.

            if(p == NULL){
                printf("\nErro na realoca��o!");    //Verificando se a realoca��o de mem�ria ocorreu bem.
                exit(1);
            }

            preencher(p, tam);          //Chamada para a fun��o "preencher".

            tam++;                      //Incremento de +1 a cada novo funcion�rio.

            alterarSal(p, tam);         //Chamada para a fun��o "alterarSal".

        }else{
            system("cls");
            break;
        }

    } while (test != 'N' || test != 'n');

    system("cls");
    printf("\nTerminando a execu��o!\n\n");

    maiorMenorSal(p, tam);              //Chamando as fun��es "maiorMenorSal" e "imprimir".
    imprimir(p, tam);
    free(p);                            //Liberando mem�ria ao fim da execu��o.

    return 0;
}