#include <stdio.h>
#include <stdlib.h>
#include "pilha.c"

int main(){
    Pilha *p = NULL;
    
    p = pilha_cria();

    pilha_push(p, 10.0);
    pilha_push(p, 13.0);
    pilha_push(p, 20.0);
    pilha_push(p, 230.0);

    pilha_pop(p);
    pilha_pop(p);

    pilha_imprimir(p);

    pilha_libera(p);

    return 0;
}