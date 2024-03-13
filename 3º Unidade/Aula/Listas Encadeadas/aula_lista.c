#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

// AULA: Listas Encadeadas

struct lista{
    int info;
    Lista *prox;
};

Lista *lista_Cria(void){
    return NULL;
}

Lista *lista_insere(Lista *list, int valor){
    // Aloca novo nó da lista encadeada.
    Lista *novo = (Lista*)malloc(sizeof(Lista));

    if(novo == NULL){
        exit(1);
    }

    //Adiciona o valor no campo "info".
    novo->info = valor;

    //Conecta o novo nó da lista.
    novo->prox = list;

    return novo;
}

void VerificaLista(Lista *lista){
    if(lista == NULL){
        printf("A lista esta vazia!");
    }else{
        printf("A lista tem elementos!");
    }
}

Lista *RemoveLista(Lista *lista, int valor){
    Lista *aux, *contador = NULL;

    aux = lista;

    while(aux != NULL && aux->info != valor){
        contador = aux;
        aux = aux->prox;
    }

    if(aux != NULL){
        if(contador != NULL){
            contador->prox = aux->prox;
        }else{
            lista = aux->prox;
        }
        free(aux);
    }
    
    return lista;
}

void Busca(Lista *lista, int valor){
    Lista *contador;

    for(contador = lista; contador != NULL; contador = contador->prox){
        if(contador->info == valor){
            printf("Valor encontrado: %d\n", contador->info);
        }
    }
}

void Imprimir(Lista *lista){
    Lista *contador;

    for(contador = lista; contador != NULL; contador = contador->prox){
        printf("Elementos: ");
        printf("%d ", contador->info);
    }
}

void LiberarLista(Lista *lista){
    Lista *aux;

    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        free(aux);
    }

}