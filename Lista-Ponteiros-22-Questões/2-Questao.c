#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m = 29, *ab;

    printf("Endere�o de m: %p\nValor de m: %d\n\n", &m, m);

    ab = &m;

    printf("Endere�o do ponteiro ab: %p\n", ab);
    printf("Conte�do do ponteiro ab: %d\n\n", *ab);

    m = 34;

    printf("Endere�o do ponteiro ab: %p\n", ab);
    printf("Conte�do do ponteiro ab: %d\n\n", *ab);

    *ab = 7;

    printf("Endere�o de m: %p\nValor de m: %d\n\n", &m, m);

    return 0;
}