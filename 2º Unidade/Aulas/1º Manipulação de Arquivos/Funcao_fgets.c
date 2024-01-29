#include <stdio.h>
#include <stdlib.h>
/*
AULA: Função para ler dados:
- char *fgets (ler uma string)
*/
int main(){

    FILE *arquivo;

    arquivo = fopen("entrada.txt", "wt");
    char c[20];

    if(arquivo == NULL){
        printf("Erro na abertura");
        exit(1);
    }else{
        printf("Arquivo Aberto!");
    }

    //Exemplo 3:
    fscanf(arquivo, "%[^\n]s", c);
    printf("%s", c);

    if(fclose(arquivo) == 0){        // Fecha o arquivo criado
        printf("\nArquivo fechado com sucesso!");
    }        
    
    return 0;
}