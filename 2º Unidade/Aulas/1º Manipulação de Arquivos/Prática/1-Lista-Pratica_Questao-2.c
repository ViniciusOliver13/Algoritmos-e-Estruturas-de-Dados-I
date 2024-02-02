#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo_entrada = fopen("entrada_q2.txt", "rt");
    FILE *arquivo_saida = fopen("saida_q2.txt", "wt");
    int i = 0, maior = 0, menor= 0, num[10];
    float media;

    while(fscanf(arquivo_entrada, "%d", &num[i]) == 1){
        i++;
    }

    maior = num[0];
    menor = num[0];

    for( i = 1; i < 10; i++){
        if(maior < num[i]){
            maior = num[i];
        }

        if(menor > num[i]){
            menor = num[i];
        }
        media += num[i];
    }

    fprintf(arquivo_saida, "Menor número: %d\nMaior número: %d\nMédia: %.2f", maior, menor, media / 10);

    if (fclose(arquivo_entrada) == 0) {
        printf("Arquivo fechado!");
    }

    if (fclose(arquivo_saida) == 0) {
        printf("Arquivo modificado!");
    }

    return 0;
}