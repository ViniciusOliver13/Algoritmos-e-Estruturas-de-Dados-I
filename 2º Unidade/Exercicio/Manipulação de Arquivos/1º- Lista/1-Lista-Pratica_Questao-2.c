#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE *arquivo_entrada = fopen("entrada_q2.txt", "rt");      //Abrindo o arquivo entrada no modo de leitura.
    FILE *arquivo_saida = fopen("saida_q2.txt", "wt");      // Abrindo o arquivo saida no modo de escrita de texto. 

    int i = 0, maior = 0, menor= 0, num[10];
    float media;

    while(fscanf(arquivo_entrada, "%d", &num[i]) == 1){     //Lendo o conteúdo do arquivo de entrada com a função "fscanf()".
        i++;
    }

    maior = num[0];
    menor = num[0];

    for( i = 1; i < 10; i++){
        if(maior < num[i]){         //Função para descubrir o maior número.
            maior = num[i];
        }

        if(menor > num[i]){         //Função para descubrir o menor número.        
            menor = num[i]; 
        }
        media += num[i];            
    }

    fprintf(arquivo_saida, "Menor número: %d\nMaior número: %d\nMédia: %.2f", maior, menor, media / 10);        //Adicionando as informações no arquivo de saída com a função "fprintf()".

    if (fclose(arquivo_entrada) == 0) {
        printf("Arquivo fechado!");
    }

    if (fclose(arquivo_saida) == 0) {
        printf("Arquivo modificado!");
    }

    return 0;
}