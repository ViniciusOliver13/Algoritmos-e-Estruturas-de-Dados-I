#include <stdio.h> 
#include <stdlib.h>

typedef struct lista{
    float num;
    struct lista *prox;
} Lista;

Lista *insere_Lista(Lista *p, float valor){
    Lista *novo = (Lista *)malloc(sizeof(Lista));

    if(novo == NULL){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }

    novo->num = valor;
    novo->prox = p;
    p = novo;

    return novo;
}

Lista *contatena(Lista *lista_1, Lista *lista_2){
    Lista *p = lista_1;

    while(p->prox != NULL){
        p = p->prox;
    }

    p->prox = lista_2;

    return lista_1;
}

Lista *cria_lista(){
    return NULL;
}

int main(){

    Lista *lista_1 = cria_lista();
    Lista *lista_2 = cria_lista();
    Lista *contatenacao = NULL;

    lista_1 = insere_Lista(lista_1, 2.1);
    lista_1 = insere_Lista(lista_1, 4.5);
    lista_2 = insere_Lista(lista_2, 1.0);
    lista_2 = insere_Lista(lista_2, 7.2);

    contatenacao = contatena(lista_1, lista_2);

    free(lista_1);
    free(lista_2);
    free(contatenacao);

    return 0;
}