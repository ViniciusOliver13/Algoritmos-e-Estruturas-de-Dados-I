#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char *string = (char*)malloc(100 * sizeof(char));

    printf("Informe uma palavra: ");
    scanf("%s", string);

    printf("O tamanho da palavra: %d", strlen(string));

    return 0;
}