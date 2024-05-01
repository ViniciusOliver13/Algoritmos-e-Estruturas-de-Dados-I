typedef struct lista Lista;

typedef struct pilha Pilha;

Pilha *pilha_cria();

void pilha_push(Pilha *p, float valor);

float pilha_pop(Pilha *p);

int pilha_vazia(Pilha *p);

void pilha_libera(Pilha *p);
