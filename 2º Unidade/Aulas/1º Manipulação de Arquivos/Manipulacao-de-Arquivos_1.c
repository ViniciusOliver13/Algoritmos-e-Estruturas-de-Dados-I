#include <stdio.h>
#include <stdlib.h>

int main(){

    //Cria o arquivo: "escrita.txt" no modo de escrita
    FILE *arquivo = fopen("escrita.txt", "w");

    if(arquivo == NULL){
        printf("Erro na abertura");
        exit(1);
    }else{
        printf("Arquivo criado!");
    }

    //fputc('Q', arquivo);         //Adiciona um caractere ao arquivo "escrita"

    //fputs("Vinicius 13", arquivo);

    fprintf(arquivo, "Hello word!");

    if(fclose(arquivo) == 0){        // Fecha o arquivo criado
        printf("\nArquivo fechado com sucesso!");
    }        

    
    return 0;
}