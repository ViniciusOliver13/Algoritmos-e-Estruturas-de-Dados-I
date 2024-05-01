typedef struct lista Lista;

/*Função que inicializa a lista atribuindo NULL.
Retorna: Lista inicializada.
*/
Lista *lista_Cria(void);

/*Função que insere um novo elemento no inicio da lista encadeada.
Argumentos:
    Lista *Lista;
    int valor: valor inteiro a ser inserido.
Retorno:
    Nova lista.
*/
Lista *lista_insere(Lista *list, int valor);

//Função que busca um valor na lista.
void Busca(Lista *lista, int valor);

//Função que remove um elemento da lista.
Lista *RemoveLista(Lista *lista, int valor);

//Função que verifica se a lista está vazia.
void VerificaLista(Lista *lista);

//Imprimi os valores da lista.
void Imprimir(Lista *lista);

//Libera a memória da lista encadeada.
void LiberarLista(Lista *lista);