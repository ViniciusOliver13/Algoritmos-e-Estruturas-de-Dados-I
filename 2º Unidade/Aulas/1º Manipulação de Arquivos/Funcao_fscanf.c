#include <stdio.h>
#include <stdlib.h>
/*
AULA: Função para ler dados:
- int fscanf  (ler dados do arquivo)
*/

int main(){

    FILE *arquivo;

    arquivo = fopen("entrada.txt", "r");
    char c[20];

    if(arquivo == NULL){
        printf("Erro na abertura");
        exit(1);
    }else{
        printf("Arquivo Aberto!");
    }

    //Exemplo 2:
    fscanf(arquivo, "%[^\n]s", c);
    printf("%s", c);

    if(fclose(arquivo) == 0){        // Fecha o arquivo criado
        printf("\nArquivo fechado com sucesso!");
    }        

    return 0;
}