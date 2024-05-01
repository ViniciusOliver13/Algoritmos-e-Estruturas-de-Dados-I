#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
} No;

//Inserir no inicio

void inseririnicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }else{
        printf("Erro ao alocar memoria!");
    }
}

//Inserir no final

void inserirfim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        if(*lista == NULL){
            *lista = novo;
        }else{
            aux = *lista;
            while(aux ->proximo){
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memoria!");
    }
}

//Inserir no meio

void inserirMeio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo){
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }else{
        printf("Erro ao alocar memoria!");
    }
}

void imprimir(No *no){
    printf("\nLista: ");

    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){
    int opcao, valor, anterior;
    No *lista = NULL;

    do{
        printf("1- Inserir Inicio\n2- Inserir no meio\n3- Inserir no final\n4- Imprimir\n0- Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inseririnicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                printf("Digite o valor de referencia: ");
                scanf("%d", &anterior);
                inserirMeio(&lista, valor, anterior);
                break;
            case 3:
                printf("Digite um valor: ");
                scanf("%d", &valor);
                inserirfim(&lista, valor);
                break;
            case 4:
                imprimir(lista);
                break;
            default:
                if(opcao != 0){
                    printf("Opcao invalida!");
                }
        }
    } while (opcao != 0);
    

    return 0;
}