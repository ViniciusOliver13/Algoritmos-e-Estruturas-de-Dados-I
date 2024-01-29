#include <stdio.h>
#include <stdlib.h>
/*
AULA: Função para ler dados:
- int fgetc   (ler um caractere por vez)
*/
int main(){

    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");
    int c;

    if(arquivo == NULL){
        printf("Erro na abertura");
        exit(1);
    }else{
        printf("Arquivo Aberto!");
    }
   
    //Exemplo 1:
    c = fgetc(arquivo);         //Lê um caractere do arquivo
    printf("\n%c", c);

    if(fclose(arquivo) == 0){        // Fecha o arquivo criado
        printf("\nArquivo fechado com sucesso!");
    }        
    
    return 0;
}