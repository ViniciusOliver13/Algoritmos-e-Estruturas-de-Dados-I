#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int *i, m = 300;
    float *f, fx = 300.600006;
    char *c, cht = 'z';

    //USANDO O OPERADOR &:  
    printf("Endereço de m: %p\n", &m);
    printf("Endereço de fx: %p\n", &fx);
    printf("Endereço de cht: %p\n\n", &cht);

    //USANDO O OPERADOR & E *:
    printf("Valor do endeço m: %d\n", *&m);
    printf("Valor do endeço fx: %f\n", *&fx);
    printf("Valor do endeço cht: %c\n\n", *&cht);

    //USANDO APENAS VARIÁVEIS DO TIPO PONTEIRO:
    i = &m, f = &fx, c = &cht;

    printf("Endereço de m: %p\n", i);
    printf("Endereço de fx: %p\n", f);
    printf("Endereço de cht: %p\n\n", c);

    //USANDO APENAS VARIÁVEIS DO TIPO PONTEIRO
    //PARA IMPRIMIR O CONTEÚDO DAS VARIÁVEIS:
    
    printf("Conteúdo do endereço de m: %d\n", *i);
    printf("Conteúdo do endereço de fx: %f\n", *f);
    printf("Conteúdo do endereço de cht: %c\n", *c);

    return 0;
}