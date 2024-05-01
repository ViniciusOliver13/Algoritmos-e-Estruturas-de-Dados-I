#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

#define N 50

struct pilha{
    int n;
    float vet[N];
};

Pilha *pilha_cria(void){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));

    if(p == NULL){
        printf("Sem memoria!");
        exit(1);
    }else{
        p->n = 0;
    }

    return p;
}

void pilha_push(Pilha *p, float valor){
    if(p->n == N){  //Capacidade esgotada
        printf("Capacidade da pilha maxima atingida!");
        exit(1);
    }

    //Insere elementos na próxima posição livre.
    p->vet[p->n] = valor;
    p->n++;
}

int pilha_vazia(Pilha *p){
    return (p->n == 0);
}

float pilha_pop(Pilha *p){
    float valor;

    if(pilha_vazia(p)){
        printf("Pilha vazia!");
        exit(1);
    }

    // Retira elementos do topo
    valor = p->vet[p->n-1];
    p->n--;

    return valor;
}

void pilha_libera(Pilha *p){
    free(p);
}

void pilha_imprimir(Pilha *p){
    int i;

    for(i = p->n-1; i >= 0; i--){
        printf("%.2f ", p->vet[i]);
    }
}
