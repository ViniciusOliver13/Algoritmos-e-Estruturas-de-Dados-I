#include <stdio.h>
#include <stdlib.h>
/*
Aula: Manipulação de Arquivos
Função "fopen"
*/
int main(){

    FILE *arquivo;
    
    arquivo = fopen("entrada.txt", "wt");

    if(arquivo == NULL){
        printf("Erro na abertura");
        exit(1);
    }else{
        printf("Arquivo criado!");
    }

    if(fclose(arquivo) == 0){        // Fecha o arquivo criado
        printf("\nArquivo fechado com sucesso!");
    }        

    return 0;
}