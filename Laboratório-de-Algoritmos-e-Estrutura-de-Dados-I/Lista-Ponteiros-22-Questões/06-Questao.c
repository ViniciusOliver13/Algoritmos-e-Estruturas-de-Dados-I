#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void maiorNumero(int *num1, int *num2){
    if(*num1 > *num2){
        printf("O n�mero %d � maior do que %d.", *num1, *num2);

    }else if (*num2 > *num1){
        printf("O n�mero %d � maior do que %d.", *num2, *num1);

    }else{
        printf("Os n�meros s�o iguais!");
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int n1, n2;

    printf("Qual � o primeiro n�mero? ");
    scanf("%d", &n1);
    printf("Qual � o segundo n�mero? ");
    scanf("%d", &n2);

    maiorNumero(&n1, &n2);

    return 0;
}