#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void maiorNumero(int *num1, int *num2){
    if(*num1 > *num2){
        printf("O número %d é maior do que %d.", *num1, *num2);

    }else if (*num2 > *num1){
        printf("O número %d é maior do que %d.", *num2, *num1);

    }else{
        printf("Os números são iguais!");
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int n1, n2;

    printf("Qual é o primeiro número? ");
    scanf("%d", &n1);
    printf("Qual é o segundo número? ");
    scanf("%d", &n2);

    maiorNumero(&n1, &n2);

    return 0;
}