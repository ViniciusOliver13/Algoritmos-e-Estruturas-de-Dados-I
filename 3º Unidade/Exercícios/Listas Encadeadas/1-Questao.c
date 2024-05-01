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

int maiores(Lista* l, int n){
    int cont = 0;
    Lista *p = l;

    while(p != NULL){
        if(p->num > n){
            cont++;
        }
        p = p->prox;
    }

    return cont;
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

    printf("Digite um valor para comparar: ");
    scanf("%d", &valores);

    printf("Quantidade de valores maiores que %d: %d\n", valores, maiores(lista_encadeada, valores));

    free(lista_encadeada);

    return 0;
}