#include <stdio.h>
#include <stdlib.h>
#include "contabancaria.h"

int main(){

    char nome[40];
    float valor = 0;
    int numero, op, i = 0;

    ContaBancaria *clientes = (ContaBancaria*)malloc(sizeof(ContaBancaria));

    if(clientes == NULL){
        printf("Erro na alocacao!");
        exit(1);
    }

    do{
        printf("[1] Criar conta\n[2] Deposito\n[3] Sacar\n[4] Transferir\n[5] Ver saldo\n[6] Sair\n>>> ");
        scanf("%d", &op);   
                                    // OPÇÃO ADMIM
        switch (op){                // [13] Ver todas as contas
        case 1:
            printf("Informe o nome do titular: ");
            scanf(" %[^\n]", nome);
            printf("Digite o numero da conta: ");
            scanf(" %d", &numero);
            printf("CADASTRO REALIZADO!\n");
            system("pause");

            clientes[i] = *CriarConta(nome, numero, valor);
            i++;

            clientes = (ContaBancaria*)realloc(clientes, (i + 1) * sizeof(ContaBancaria));

            break;
        case 2:
            Deposita(clientes, i);
            break;
        case 3:
            Saca(clientes, i);
            break;
        case 4:
            Transfere(clientes, i);
            break;
        case 5:
            Saldo(clientes, i);
            break;
        case 6:
            ExcluiConta(clientes);
            break;
        case 13:
            verClientes(clientes, i);
            break;    
        default:
            printf("Opcao invalida!\n");
            break;
        }

    } while(op != 6);

    return 0;
}