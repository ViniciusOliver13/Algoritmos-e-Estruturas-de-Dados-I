#include <stdio.h>
#include <stdlib.h>

int soma(int a, int b){

    return a + b;
}

int subtracao(int a, int b){

    return a - b;
}

int multiplicacao(int a, int b){

    return a * b;
}

int divicao(int a, int b){

    return a / b;
}

int calcula(int x, int y, int (*operacao)(int, int)){

    return (*operacao)(x,y);
}

int main(){

    // PONTEIROS PARA FUNÇÕES
    int escolha, resultado;

    printf("DIGITE A OPCAO:");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
        resultado = calcula(5, 3, soma);
        printf("Resultado: %d", resultado);
        break;
    case 2:
        resultado = calcula(5, 3, subtracao);
        printf("Resultado: %d", resultado);
        break;
    case 3:
        resultado = calcula(5, 3, multiplicacao);
        printf("Resultado: %d", resultado);
        break;
    case 4:
        resultado = calcula(5, 2, divicao);
        printf("Resultado: %d", resultado);
        break;
    default:
        printf("opcao invalida!");
        break;
    }

    return 0;
}