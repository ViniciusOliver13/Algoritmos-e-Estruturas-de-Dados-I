#include <stdio.h>
#include <stdlib.h>

void trocar(int *p1, int *p2, int *p3){
    int aux = *p1;

    *p1 = *p3;
    *p3 = *p2;
    *p2 = aux;
}

int main(){

    int n1, n2, n3;

    printf("Digite o valor do primeiro da sequencia: ");
    scanf("%d", &n1);
    printf("Digite o valor do segundo da sequencia: ");
    scanf("%d", &n2);
    printf("Digite o valor do terceiro da sequencia: ");
    scanf("%d", &n3);

    trocar(&n1, &n2, &n3);

    printf("Valores depois da troca:\n1- %d\n2- %d\n3- %d\n", n1, n2, n3);

    return 0;
}