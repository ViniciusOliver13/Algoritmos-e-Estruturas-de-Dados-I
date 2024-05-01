typedef struct pilha Pilha;

// Função para criar uma estrutura do tipo "Pilha"
Pilha *pilha_cria(void);

// Função para empilhar elementos
void pilha_push(Pilha *p, float v);

// Função para desempilhar elementos
float pilha_pop(Pilha *p);

// Função para verificar se a pilha está vazia
int pilha_vazia(Pilha *p);

// Função que libera a memória alocada da estrutura "Pilha"
void pilha_libera(Pilha *p);

//
void pilha_imprimir(Pilha *p);