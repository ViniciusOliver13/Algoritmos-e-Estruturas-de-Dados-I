typedef struct lista Lista;

/*Fun��o que inicializa a lista atribuindo NULL.
Retorna: Lista inicializada.
*/
Lista *lista_Cria(void);

/*Fun��o que insere um novo elemento no inicio da lista encadeada.
Argumentos:
    Lista *Lista;
    int valor: valor inteiro a ser inserido.
Retorno:
    Nova lista.
*/
Lista *lista_insere(Lista *list, int valor);

//Fun��o que busca um valor na lista.
void Busca(Lista *lista, int valor);

//Fun��o que remove um elemento da lista.
Lista *RemoveLista(Lista *lista, int valor);

//Fun��o que verifica se a lista est� vazia.
void VerificaLista(Lista *lista);

//Imprimi os valores da lista.
void Imprimir(Lista *lista);

//Libera a mem�ria da lista encadeada.
void LiberarLista(Lista *lista);