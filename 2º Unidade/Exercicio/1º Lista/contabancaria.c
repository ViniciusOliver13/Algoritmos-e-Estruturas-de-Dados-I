#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contabancaria.h"

struct contabancaria{
    char titular[40];
    int numero;
    float saldo;
};

ContaBancaria *CriarConta(char *nome, int num, float valor){
    ContaBancaria *p = (ContaBancaria*)malloc(sizeof(ContaBancaria));
    
    if(p == NULL){
        printf("Sem memoria!");
        exit(1);
    }

    valor = 0;

    strcpy(p->titular, nome);
    p->saldo = valor;
    p->numero = num;

    return p;
}

void Deposita(ContaBancaria *p, int tam){
    int i, numero;
    char test = 'F';

    printf("Qual o numero da conta? ");
    scanf("%d", &numero);

    for(i = 0; i < tam; i++){

        if(numero == p[i].numero){
            printf("Qual o valor do deposito? R$");
            scanf(" %f", &p[i].saldo);
            printf("Deposito efetuado!\n");
            system("pause");
            test = 'V';
        }
    }

    if(test == 'F'){
        printf("O numero fornecido nao existe!\n");
    }
}

void Saca(ContaBancaria *p, int tam){
    int i, numero;
    float valor;
    char test = 'F';

    printf("Qual o numero da conta? ");
    scanf("%d", &numero);

    for(i = 0; i < tam; i++){

        if(numero == p[i].numero){
            printf("Titular: %s\nSaldo disponivel: R$%.2f\n", p[i].titular, p[i].saldo);
            printf("Qual o valor do saque? R$");
            scanf(" %f", &valor);

            if(valor > p[i].saldo){
                printf("Saldo insuficiente para o saque!\n");
                test = 'V';
            }else{
                p[i].saldo -= valor;
                printf("Saque efetuado!\n");
                system("pause");
                test = 'V';
            }
        }
    }  

    if(test == 'F'){
        printf("O numero fornecido nao existe!\n");
    }
}

void Saldo(ContaBancaria *p, int tam){
    int numero, i;
    char test = 'F';

    printf("Qual o numero da conta? ");
    scanf("%d", &numero);

    for(i = 0; i < tam; i++){

        if(numero == p[i].numero){
            printf("Titular: %s\nSaldo disponivel: R$%.2f\n", p[i].titular, p[i].saldo);
            system("pause");
            test = 'V';
        }
    }

    if(test == 'F'){
        printf("O numero fornecido nao existe!\n");
    }

}

void Transfere(ContaBancaria *p, int tam){
    int i, numero, numero2;
    float valor;
    char test = 'F', test2 = 'F';

    printf("Quem vai transferir?\nNumero da conta: ");
    scanf("%d", &numero);
    printf("Quem vai receber?\nNumero da conta: ");
    scanf("%d", &numero2);

    for(i = 0; i < tam; i++){

        if(numero == p[i].numero){
            test = 'V';
            numero = i;
        }
        if(numero2 == p[i].numero){
            test2 = 'V';
            numero2 = i;
        }
    }

    if(test == 'V' && test2 == 'V'){
        printf("Valor da transferencia: R$");
        scanf(" %f", &valor);

        if(valor > p[numero].saldo){
            printf("Saldo insuficiente para a transferencia!\n");
        }else{
            p[numero].saldo -= valor;
            p[numero2].saldo += valor;
            printf("Transferencia efetuada!\n");
            system("pause");
        }
    }

    if(test == 'F' && test2 == 'F'){
        printf("Os numero fornecidos nao existem!\n");
    }else if (test == 'F' && test2 == 'V'){
        printf("O numero de quem vai transferir nao existe!\n");
    }else if (test == 'V' && test2 == 'F'){
        printf("o numero de quem vai receber nao existe!\n");
    }
}

void ExcluiConta(ContaBancaria *p){
    free(p);
    printf("Memoria liberada!\n");
}
void verClientes(ContaBancaria *p, int tam){     
    int i;

    printf("\n**OPCAO ADMIM**\n\nLista de Clientes:\n");
    for (i = 0; i < tam; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Nome: %s\n", p[i].titular);
        printf("Numero da Conta: %d\n", p[i].numero);
        printf("Saldo: R$%.2f\n\n", p[i].saldo);
    }
}
