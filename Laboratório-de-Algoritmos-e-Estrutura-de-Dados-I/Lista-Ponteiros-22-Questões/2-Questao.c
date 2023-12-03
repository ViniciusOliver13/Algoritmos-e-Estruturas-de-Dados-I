#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m = 29, *ab;

    printf("Endereço de m: %p\nValor de m: %d\n\n", &m, m);

    ab = &m;

    printf("Endereço do ponteiro ab: %p\n", ab);
    printf("Conteúdo do ponteiro ab: %d\n\n", *ab);

    m = 34;

    printf("Endereço do ponteiro ab: %p\n", ab);
    printf("Conteúdo do ponteiro ab: %d\n\n", *ab);

    *ab = 7;

    printf("Endereço de m: %p\nValor de m: %d\n\n", &m, m);

    return 0;
}