#include <stdio.h>
#include <stdlib.h>
#include "1-A) pilha.c"

int main(){
    Pilha *p = NULL;
    int i;

    p = pilha_cria();

    for(i = 0; i < 10; i++){
        pilha_push(p, i);
    }

    pilha_pop(p);
    pilha_pop(p);
    
    pilha_imprimir(p);

    pilha_libera(p);

    return 0;
}