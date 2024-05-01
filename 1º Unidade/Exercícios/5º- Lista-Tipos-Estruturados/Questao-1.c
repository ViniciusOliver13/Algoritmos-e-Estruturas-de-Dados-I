#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct ingresso{
    float preco;
    char local[20];
    char atracao[30];
} Ingresso;

void preencher(Ingresso *p, int t){
    int i;

    for(i = 0; i < t; i++){
        printf("============\n%d� Ingresso\n============\n", i + 1);
        printf("Informe o pre�o: R$");
        scanf("%f", &p[i].preco);
        printf("Qual a atra��o? ");
        fflush(stdin);
        fgets(p[i].atracao, 30, stdin);
        printf("Local da apresenta��o: ");
        fgets(p[i].local, 20, stdin);
        fflush(stdin);
    }

}

void imprimir(Ingresso *p, int t){
    int i;

    system("cls");

    for(i = 0; i < t; i++){
        printf("-=-=-=-=-=-=-\n%d� Ingresso\n", i + 1);
        printf("Nome: %s", p[i].atracao);
        printf("Local: %s", p[i].local);
        printf("Pre�o:R$ %.2f\n", p[i].preco);
        printf("-=-=-=-=-=-=-\n");
    }

}

void novo_valor(Ingresso *p, int t){
    char test;
    int opcao = 0;

    printf("Deseja alterar o pre�o de algum ingresso? [S/N]");
    scanf(" %c", &test);

    if(test == 'S' || test == 's'){

        while (t >= 0){
            printf("Digite o n�mero(�) do imgresso: ");
            scanf("%d", &opcao);

            if(opcao > t){
                printf("Ingresso Inv�lido!\n");
            }else{
                printf("Valor do Ingresso: R$%.2f\n", p[opcao-1].preco);
                printf("Qual o novo valor? R$");
                scanf(" %f", &p[opcao-1].preco);
                break;
            }
            
        }
        printf("Valor alterado com sucesso!\n");
        system("pause");
    }
    system("cls");
}

void Preco_menorEmaior(Ingresso *p, int t){
    int maior = 0, menor = 0, i = 0;
    float preco_maior = p[0].preco;  
    float preco_menor = p[0].preco;  

    for (i = 1; i < t; i++){
        if (preco_maior < p[i].preco){
            preco_maior = p[i].preco;
            maior = i;
        }
        if (preco_menor > p[i].preco){
            preco_menor = p[i].preco;
            menor = i;
        }
    }

    printf("-=-=-=-=-=-=-\n%d� Ingresso Mais Caro\n", maior + 1);
    printf("Nome: %sLocal: %sPre�o: R$ %.2f\n-=-=-=-=-=-=-\n", p[maior].atracao, p[maior].local, p[maior].preco);
    printf("-=-=-=-=-=-=-\n%d� Ingresso Mais Barato\n", menor + 1);
    printf("Nome: %sLocal: %sPre�o: R$ %.2f\n-=-=-=-=-=-=-\n", p[menor].atracao, p[menor].local, p[menor].preco);
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int tam;

    printf("Qual o n�mero de ingressos? ");
    scanf("%d", &tam);

    Ingresso *token = (Ingresso*) malloc(sizeof(Ingresso) * tam);

    if(token == NULL){
        printf("Erro na aloca��o!");
        exit(1);
    }
    
    preencher(token, tam);
    imprimir(token, tam);
    novo_valor(token, tam);
    Preco_menorEmaior(token, tam);

    free(token);

    return 0;
}