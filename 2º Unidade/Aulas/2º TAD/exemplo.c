#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"    //Importando o arquivo que possuí os protótipos das funções.

// PRÁTICA DA AULA: "Implementação de funções matemáticas"

int main(){
    
    int num1, num2, op;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);

    system("cls");

    printf("[1] adicao\n[2] subtracao\n[3] multiplicacao\n[4] divisao\n[5] potenciacao\n>>>");
    scanf("%d", &op);

    switch (op){

    case 1:
        printf("resultado = %d", adicao(num1, num2));
        break;
    case 2:
        printf("resultado = %d", subtracao(num1, num2));
        break;
    case 3:
        printf("resultado = %d", multiplicacao(num1, num2));
        break;
    case 4:
        printf("resultado = %f", divisao(num1, num2));
        break;
    case 5:
        printf("resultado = %d", potenciacao(num1, num2));
        break;
    default:
        printf("Opcao invalida!");
        break;
    }
    
    return 0;
}