typedef struct ingresso Ingresso;

//Fun��o que recebe os dados do ingresso via teclado.
void preencher(Ingresso *ponteiro, int t);

//Fun��o para modificar o pre�o de algum ingresso.
void novo_valor(Ingresso *ponteiro, int t);

//Fun��o para saber qual � o ingresso mais caro e o mais barato.
void Preco_menorEmaior(Ingresso *ponteiro, int t);

//Fun��o que imprimi os dados de todos os ingressos.
void imprimir(Ingresso *ponteiro, int t);
