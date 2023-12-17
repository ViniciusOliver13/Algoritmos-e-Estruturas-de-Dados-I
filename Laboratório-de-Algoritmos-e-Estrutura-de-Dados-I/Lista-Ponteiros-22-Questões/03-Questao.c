#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int *i, m = 300;
    float *f, fx = 300.600006;
    char *c, cht = 'z';

    //USANDO O OPERADOR &:  
    printf("Endere�o de m: %p\n", &m);
    printf("Endere�o de fx: %p\n", &fx);
    printf("Endere�o de cht: %p\n\n", &cht);

    //USANDO O OPERADOR & E *:
    printf("Valor do ende�o m: %d\n", *&m);
    printf("Valor do ende�o fx: %f\n", *&fx);
    printf("Valor do ende�o cht: %c\n\n", *&cht);

    //USANDO APENAS VARI�VEIS DO TIPO PONTEIRO:
    i = &m, f = &fx, c = &cht;

    printf("Endere�o de m: %p\n", i);
    printf("Endere�o de fx: %p\n", f);
    printf("Endere�o de cht: %p\n\n", c);

    //USANDO APENAS VARI�VEIS DO TIPO PONTEIRO
    //PARA IMPRIMIR O CONTE�DO DAS VARI�VEIS:
    
    printf("Conte�do do endere�o de m: %d\n", *i);
    printf("Conte�do do endere�o de fx: %f\n", *f);
    printf("Conte�do do endere�o de cht: %c\n", *c);

    return 0;
}