#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int n1, n2, soma, *num1 = &n1, *num2 = &n2;

    printf("Informe o primeiro n�mero: ");
    scanf("%d", &n1);
    printf("Informe o segundo n�mero: ");
    scanf("%d", &n2);

    soma = *num1 + *num2;

    printf("A soma entre os n�meros informados foi %d.", soma);
    
    return 0;
}