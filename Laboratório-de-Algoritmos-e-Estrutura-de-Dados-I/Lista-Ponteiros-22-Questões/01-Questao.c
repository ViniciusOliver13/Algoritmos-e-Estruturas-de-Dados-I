#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m = 10, n, o, *z;

    z = &m;

    printf("z armazena o endere�o de m: %p\n", z);
    printf("z armazena o conte�do de m: %d\n\n", *z);

    printf("&m � o endere�o de m: %p\n", &m);
    printf("&n � o endere�o de n: %p\n", &n);
    printf("&o � o endere�o de o: %p\n", &o);
    printf("&z � o endere�o de z: %p\n\n", &z);

    return 0;
}