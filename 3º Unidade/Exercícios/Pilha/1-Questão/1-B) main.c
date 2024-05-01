#include <stdio.h>
#include <stdlib.h>
#include "1-B) Questao.c"

int main(){
    Pilha *p = pilha_cria();

    pilha_push(p, 10);
    pilha_push(p, 20);
    pilha_push(p, 30);

    printf("Valor retirado: %.2f\n", pilha_pop(p));
        
    pilha_libera(p);

    return 0;
}