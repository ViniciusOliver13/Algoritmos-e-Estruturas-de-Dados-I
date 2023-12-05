#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int soma(int a, int b){

    return a + b;
}

int subtracao(int a, int b){

    return a - b;
}

int multiplicacao(int a, int b){

    return a * b;
}

int divicaoInteira(int a, int b){

    return a / b;
}

int calcula(int x, int y, int (*operacao)(int, int)){

    return (*operacao)(x,y);
}

void numeros(int *n1, int *n2){
    printf("Digite o 1º valor: ");
    scanf("%d", n1);
    printf("Digite o 2º valor: ");
    scanf("%d", n2);
}
int main(){
    setlocale(LC_ALL,"Portuguese");

    // ASSUNTO: *** PONTEIROS PARA FUNÇÕES ***
    int escolha, resultado, num1, num2;

    do{
        printf("----------------------\n[1] SOMA\n[2] SUBTRAÇÃO\n[3] MULTIPLICAÇÃO\n[4]" 
        " DIVISÃO INTEIRA\n[5] SAIR\n----------------------\n");
        printf("DIGITE UMA OPÇÃO: ");
        scanf("%d", &escolha); 

        //numeros(&num1, &num2); --- >>> CHAMADA PARA O PROCEDIMENTO DE PREENCHER OS 2 NÚMEROS

        switch (escolha){
            case 1:
                numeros(&num1, &num2);
                resultado = calcula(num1, num2, soma);
                printf("Resultado da SOMA: %d\n", resultado);
                break;
            case 2:
                numeros(&num1, &num2);
                resultado = calcula(num1, num2, subtracao);
                printf("Resultado da SUBTRAÇÃO: %d\n", resultado);
                break;
            case 3:
                numeros(&num1, &num2);
                resultado = calcula(num1, num2, multiplicacao);
                printf("Resultado da MULTIPLIÇÃO: %d\n", resultado);
                break;
            case 4:
                numeros(&num1, &num2);
                resultado = calcula(num1, num2, divicaoInteira);
                printf("Resultado da DIVISÃO INTEIRA: %d\n", resultado);
                break;
            case 5:
                printf("Saindo...");
                exit(0);
            default:
                printf("opção inválida!\n");
                break;
        }

    system("pause");
    system("cls");
    
    }while(escolha != 5);
    
    return 0;
}
