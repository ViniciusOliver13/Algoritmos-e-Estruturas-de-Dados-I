#include <stdlib.h>
#include "1-A) pilha.h"

struct pilha{
    int n;
    float *vet;
};

Pilha *pilha_cria(){
    Pilha *p = (Pilha*)malloc(sizeof(Pilha));

    if(p == NULL){
        exit(1);
    }

    p->vet = (float*) malloc(sizeof(float));

    if(p->vet == NULL){
        exit(1);
    }

    p->n = 0;

    return p;
}

void pilha_push(Pilha *p, float valor){
    p->vet = (float*) realloc(p->vet, (p->n + 1) * sizeof(float));
    
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

void pilha_imprimir(Pilha *p){
    int i = 0 ;

    for(i = 0; i < p->n; i++){
        printf("%.2f\n", p->vet[i]);
    }
}

void pilha_libera(Pilha *p){
    free(p->vet);
    free(p);
}

