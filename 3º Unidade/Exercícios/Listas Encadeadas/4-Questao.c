#include <stdio.h> 
#include <stdlib.h>

typedef struct lista{
    int num;
    struct lista *prox;
} Lista;

Lista *insere_Lista(Lista *p, int valor){
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

Lista *cria_lista(){
    return NULL;
}

Lista *retira_n(Lista *lista, int valor){

    Lista *anterior = NULL;
    Lista *p = lista;
    Lista *test = lista;
    int i, verifica = 0;

    while(test != NULL){
        if(test->num == valor){
            verifica++;
        }
        test = test->prox;
    }

    for(i = 0; i < verifica; i++){
        p = lista;
        anterior = NULL;

        while(p != NULL && p->num != valor){
            anterior = p;
            p = p->prox;
        }

        if(p == NULL){
            return lista;
        }

        if(anterior == NULL){
            lista = p->prox;
        }else{
            anterior->prox = p->prox;
        }

        free(p);
    }

    return lista;
}

int main(){

    Lista *lista_encadeada = cria_lista();
    int valores = 0;

    while (valores != 999){
        printf("Digite um valor (999 se encerra): ");
        scanf("%d", &valores);

        if(valores != 999){
            lista_encadeada = insere_Lista(lista_encadeada, valores);
        }else{
            system("cls");
            break;
        }
        printf("Elemento adicionado com sucesso!\n");
        system("cls");
    }

    printf("Digite um valor para retirar da lista: ");
    scanf("%d", &valores);

    lista_encadeada = retira_n(lista_encadeada, valores);

    while(lista_encadeada != NULL){
        printf("%d ", lista_encadeada->num);
        lista_encadeada = lista_encadeada->prox;
    }

    free(lista_encadeada);

    return 0;
}