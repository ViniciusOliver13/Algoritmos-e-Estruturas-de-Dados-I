#include <stdio.h>
#include <stdlib.h>
#include "fila.c"

int main(){

    int i, elem = 10;

    Fila *Q = CriaFila(10);

    if(FilaVazia(Q)){
        printf("Fila vazia\n");
    }else{
        printf("Fila nao vazia\n");
    }

    if(FilaCheia(Q)){
        printf("A fila esta cheia\n");
    }else{
        printf("A fila nao esta cheia\n");
    }

    for(i = 1; i < 11; i++){
        InsereFila(Q, i);
    }
    
    if(RemoveFila(Q)){
        printf("Elemento removido\n");
    }else{
        printf("Elemento nao foi removido\n");
    }
    
    if(ConsultarFila(Q, &elem)){
        printf("elem = %d", elem);
    }else{
        printf("O elemento nao esta na fila!");
    }

    DestruirFila(&Q);

    return 0;
}
