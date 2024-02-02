#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo_entrada = fopen("entrada_3q.txt", "r");
    FILE *arquivo_saida = fopen("sainda_3q.txt", "wt");
    int i, tam;
    char nome[50];
    float n1, n2, n3, media = 0;

    if(arquivo_entrada == NULL){
        printf("Erro ao abrir o arquivo de entrada!");
        exit(1);
    }

    while(sscanf(arquivo_entrada, "%20[^\t]\t%f\t%f\t%f", nome, &n1, &n2, &n3) != 1){
        media = (n1 + n2 + n3) / 3 ;
        fprintf(arquivo_saida, "%s\t%.2f\t%s\n", nome, media, media >= 7.0 ? "Aprovado" : "Reprovado");
        media = 0.0;
    }
    
    if(arquivo_saida == NULL){
        printf("Erro ao abrir o arquivo de saida!");
        exit(1);
    }    
    
    if(fclose(arquivo_entrada) == 0){
        printf("Arquivo fechado!");
    }
    if(fclose(arquivo_saida)){
        printf("Arquivo fechado");
    }

    return 0;
}