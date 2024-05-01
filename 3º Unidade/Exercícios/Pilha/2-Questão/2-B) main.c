#include <stdio.h>
#include <stdlib.h>
#include "2-B) pilha.c"

int main(){

    Pilha *p1 = pilha_cria();
    Pilha *p2 = pilha_cria();

    pilha_push(p1, 10);
    pilha_push(p1, 20);
    pilha_push(p1, 30);

    pilha_push(p2, 40);
    pilha_push(p2, 50);

    concatena(p1, p2);
        
    pilha_libera(p1);
    pilha_libera(p2);

    return 0;
}