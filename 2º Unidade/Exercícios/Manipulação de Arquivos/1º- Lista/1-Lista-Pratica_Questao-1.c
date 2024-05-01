#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo_entrada = fopen("entrada_3q.txt", "r");     //Abrindo o arquivo entrada no modo de leitura.
    FILE *arquivo_saida = fopen("saida_3q.txt", "wt");      // Abrindo o arquivo saida no modo de escrita de texto.  

    char nome[50];
    float n1, n2, n3, media = 0;

     while(fscanf(arquivo_entrada, "%s\t%f\t%f\t%f\n", nome, &n1, &n2, &n3) == 4){      //Lendo o conteúdo do arquivo de entrada com a função "fscanf()".
        media = (n1 + n2 + n3) / 3;
        fprintf(arquivo_saida, "%s\t\tMEDIA: %.2f\t\t%s\n", nome, media, media >= 7.0 ? "Aprovado" : "Reprovado");      //Adicionando as informações ao arquivo de saida com a função "fprinf()".
        media = 0.0;
    }
    
    if(fclose(arquivo_entrada) == 0){
        printf("Arquivo fechado!");
    }

    if(fclose(arquivo_saida) == 0){
        printf("Arquivo modificado!");
    }

    return 0;
}