/*
**** Quest�o 2) Considere o trecho de c�digo abaixo: ****
    int main(void) {
        int x, *p;
        x = 100;
        p = x;
        printf(?Valor de p = %p\tValor de *p = %d?, p, *p);
}

**** RESPOSTAS ****
A) Uma mensagem de advert�ncia.

B) Porque a vari�vel 'p' � do tipo ponteiro de inteiro e recebe o conte�do da vari�vel 'x',
mas o ponteiro armazena endere�os de mem�ria n�o o conte�do ou valores. Por fim, ao imprimir
o endere�o de 'p' n�o se sabe para onde ele est� apontando e muito menos o seu conte�do, algo
que passa a ser aleat�rio.

C) Antes da execu��o, j� podemos ver algumas advert�ncias que o pr�prio compilador faz. N�o, a exe-
cu��o n�o ocorre de maneira satisfat�ria como previsto. 

D) C�digo abaixo na linha 31.

E) Sim, a execu��o ocorreu e est� cumprindo seu papel de imprimir na tela o endere�o da vari�vel 'x'
e seu respectivo conte�do de valor 100.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d ", p, *p); 

}