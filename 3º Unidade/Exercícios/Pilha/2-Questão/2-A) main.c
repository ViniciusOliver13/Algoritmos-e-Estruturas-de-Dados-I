#include <stdio.h>
#include <stdlib.h>
#include "2-A) pilha.c"

int main(){

    Pilha *p = pilha_cria();

    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    printf("Valor do topo da piha: %.2f\n", topo(p));
        
    pilha_libera(p);

    return 0;
}