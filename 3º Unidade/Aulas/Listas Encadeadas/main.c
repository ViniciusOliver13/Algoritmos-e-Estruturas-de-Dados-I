#include <stdio.h>
#include <stdlib.h>
#include "aula_lista.c"

int main(){
    //Cria uma lista encadeada.
    Lista *lista_encadeada = lista_Cria();

    // Inserindo o valor no campo encadeada.
    lista_encadeada = lista_insere(lista_encadeada, 13);
    lista_encadeada = lista_insere(lista_encadeada, 10);

    lista_encadeada = RemoveLista(lista_encadeada, 10);

    VerificaLista(lista_encadeada);

    Busca(lista_encadeada, 13);

    Imprimir(lista_encadeada);

    return 0;
}