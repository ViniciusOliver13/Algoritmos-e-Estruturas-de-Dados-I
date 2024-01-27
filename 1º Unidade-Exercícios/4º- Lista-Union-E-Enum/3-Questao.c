#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef enum mes{Janeiro=1, Fevereiro, Marco, Abril, Maio, Junho, Julho, Agosto, Setembro, Outubro, Novembro, Dezembro} Mes;

typedef struct data{
    int dia, ano;
    Mes m;
} Data;

int main(){
    setlocale(LC_ALL, "Portuguese");

    Data *atual = malloc(sizeof(Data));

    if (atual == NULL){
        printf("Erro na aloca��o!");
        exit(1);
    }

    printf("Digite o dia do m�s: ");
    scanf("%u", &atual->dia);
    printf("Digite o m�s do ano: ");
    scanf("%u", &atual->m);
    printf("Informe o ano: ");
    scanf("%u", &atual->ano);

    printf("\n>>>> %02d/%02d/%d", atual->dia, atual->m, atual->ano);

    free(atual);

    return 0;
}