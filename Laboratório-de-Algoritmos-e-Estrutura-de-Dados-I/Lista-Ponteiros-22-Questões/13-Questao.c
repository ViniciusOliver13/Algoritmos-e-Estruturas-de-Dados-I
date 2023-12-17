#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void contagem(char *point, int tam){
    int i, vogal = 0, consoante = 0;
    for ( i = 0; i < tam; i++){
        if(point[i] == 'A' || point[i] == 'E' || point[i] == 'I' || point[i] == 'O' || point[i] == 'U'){
            vogal++;
        }else{
            consoante++;
        }
    }
    printf("Quantidade de vogais: %d\nQuantidade de consoantes: %d", vogal, consoante);
}

int main(){
    int i;
    char palavra[30], *point = NULL;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    strupr(palavra);
    contagem(palavra, strlen(palavra));

    return 0;
}