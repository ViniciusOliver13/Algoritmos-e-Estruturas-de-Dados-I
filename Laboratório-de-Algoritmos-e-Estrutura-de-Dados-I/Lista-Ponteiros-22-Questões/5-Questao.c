#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void somaReferencia(int *n1, int *n2){
    int soma;

    soma = *n1 + *n2;

    printf("A soma dos números informados foi %d.", soma);

}
int main(){
    setlocale(LC_ALL,"Portuguese");

    int num1, num2;

    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    somaReferencia(&num1, &num2);

    return 0;
}