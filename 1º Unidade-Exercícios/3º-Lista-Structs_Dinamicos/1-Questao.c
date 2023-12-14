#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct funcionario{                     //Declarando a struct "funcionario".
    char nome[50], cargo[30];
    int identificador;
    float salario;
} funcionario;

void preencher(funcionario *point, int tam){    //Função para preencher o vetor de structs "funcionario".

    printf("Nome: ");
    scanf(" %[^\n]", point[tam].nome);
    printf("Cargo: ");
    scanf(" %[^\n]", point[tam].cargo);
    printf("Salário: R$");
    scanf("%f", &point[tam].salario);
    printf("Identificador: " );
    scanf("%d", &point[tam].identificador);
}

void alterarSal(funcionario *point, int tam){   //Função para alterar o salário de algum funcionário cadastrado.
    char test;
    int z, i;

    printf("Deseja mudar o salário de algum funcionário?");
    scanf(" %c", &test);

    if(test == 'S' || test == 's'){
        system("cls");

        for(i = 0; i < tam; i++){
            printf("Nome do funcionário: %s\nIdentificador: %d\n\n", point[i].nome, point[i].identificador);
        }

        printf("Digite o identificador: ");
        scanf("%d", &i);

        for(z = 0; z < tam; z++){
            if(point[z].identificador == i){
                printf("Salário atual desse funcionário: R$%.2f\nQual é o novo salário? R$", point[z].salario);
                scanf(" %f", &point[z].salario);
                printf("Salário modificado com sucesso!!\n");
                break;
            }
        }
        printf("Funcionário não encontrado!");
        system("pause");  
    }
}

void maiorMenorSal(funcionario *point, int tam){    //Função para saber o funcionário com o maior e o menor salário e também seu cargo.
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
    printf("\n=====================\nFuncionário com o maior salário:\n");
    printf("Nome: %s\nCargo: %s\nSalário: R$%.2f\n", point[maior].nome, point[maior].cargo, point[maior].salario);      //Imprimindo o nome, cargo, salários desses funcionários
    printf("=====================\nFuncionário com o menor salário:\n");
    printf("Nome: %s\nCargo: %s\nSalário: R$%.2f\n=====================", point[menor].nome, point[menor].cargo, point[menor].salario);
}

void imprimir(funcionario *point, int tam){     //Função para imprimir o nome, cargo, salário e identificador de todos os funcionários cadastrados.  
    int i;

    for ( i = 0; i < tam; i++){
        printf("---------------------\n");
        printf("Nome: %s\n", point[i].nome); 
        printf("Cargo: %s\n", point[i].cargo);
        printf("Salário: %.2f\n", point[i].salario);
        printf("Identificador: %d\n", point[i].identificador); 
    }
    printf("---------------------");
}

int main(){
    setlocale(LC_ALL,"Portuguese");

    int tam = 0;
    char test; 
    funcionario *p = (funcionario*) malloc(sizeof(funcionario));    //Alocando memória para a variável "p"do tamanho do tipo "funcionario".

    if(p == NULL){
        printf("\nErro na alocação!");      //Verificando se a alocação de memória ocorreu bem.
        exit(1);    
    }

    do{                                     //Iniciando o laço de repetição "do while()" para perguntar ao usuário se ele quer adicionar um funcionário.

        printf("Adicionar funcionario? ");      
        scanf(" %c", &test);

        if(test == 'S' || test == 's'){
            
            system("cls");

            p = (funcionario*) realloc(p, (tam + 1) * sizeof(funcionario));     //Realocando a memória conforme novos funcionários são adicionados.

            if(p == NULL){
                printf("\nErro na realocação!");    //Verificando se a realocação de memória ocorreu bem.
                exit(1);
            }

            preencher(p, tam);          //Chamada para a função "preencher".

            tam++;                      //Incremento de +1 a cada novo funcionário.

            alterarSal(p, tam);         //Chamada para a função "alterarSal".

        }else{
            system("cls");
            break;
        }

    } while (test != 'N' || test != 'n');

    system("cls");
    printf("\nTerminando a execução!\n\n");

    maiorMenorSal(p, tam);              //Chamando as funções "maiorMenorSal" e "imprimir".
    imprimir(p, tam);
    free(p);                            //Liberando memória ao fim da execução.

    return 0;
}
