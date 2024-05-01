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

Lista *ultimo_no(Lista *lista){
    Lista *p = lista;

    while(p->prox != NULL){
        p = p->prox;
    }

    return p;
}

int main(){

    Lista *lista_encadeada = cria_lista();
    Lista *ultimo = NULL;
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

    ultimo = ultimo_no(lista_encadeada);
    printf("Conteudo do ultimo no: %d\n", ultimo->num);

    free(lista_encadeada);

    return 0;
}