/*
**** Questão 2) Considere o trecho de código abaixo: ****
    int main(void) {
        int x, *p;
        x = 100;
        p = x;
        printf(?Valor de p = %p\tValor de *p = %d?, p, *p);
}

**** RESPOSTAS ****
A) Uma mensagem de advertência.

B) Porque a variável 'p' é do tipo ponteiro de inteiro e recebe o conteúdo da variável 'x',
mas o ponteiro armazena endereços de memória não o conteúdo ou valores. Por fim, ao imprimir
o endereço de 'p' não se sabe para onde ele está apontando e muito menos o seu conteúdo, algo
que passa a ser aleatório.

C) Antes da execução, já podemos ver algumas advertências que o próprio compilador faz. Não, a exe-
cução não ocorre de maneira satisfatória como previsto. 

D) Código abaixo na linha 31.

E) Sim, a execução ocorreu e está cumprindo seu papel de imprimir na tela o endereço da variável 'x'
e seu respectivo conteúdo de valor 100.

*/

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p\tValor de *p = %d ", p, *p); 

}