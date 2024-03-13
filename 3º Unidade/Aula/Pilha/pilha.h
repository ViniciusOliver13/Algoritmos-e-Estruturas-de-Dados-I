typedef struct pilha Pilha;

// Fun��o para criar uma estrutura do tipo "Pilha"
Pilha *pilha_cria(void);

// Fun��o para empilhar elementos
void pilha_push(Pilha *p, float v);

// Fun��o para desempilhar elementos
float pilha_pop(Pilha *p);

// Fun��o para verificar se a pilha est� vazia
int pilha_vazia(Pilha *p);

// Fun��o que libera a mem�ria alocada da estrutura "Pilha"
void pilha_libera(Pilha *p);

//
void pilha_imprimir(Pilha *p);