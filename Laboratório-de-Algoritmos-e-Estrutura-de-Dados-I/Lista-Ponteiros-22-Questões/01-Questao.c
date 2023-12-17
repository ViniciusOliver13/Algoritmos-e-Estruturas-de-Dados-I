#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    int m = 10, n, o, *z;

    z = &m;

    printf("z armazena o endereço de m: %p\n", z);
    printf("z armazena o conteúdo de m: %d\n\n", *z);

    printf("&m é o endereço de m: %p\n", &m);
    printf("&n é o endereço de n: %p\n", &n);
    printf("&o é o endereço de o: %p\n", &o);
    printf("&z é o endereço de z: %p\n\n", &z);

    return 0;
}