//Definição de novo tipo: Aluno
typedef struct aluno Aluno;

//Função que aloca memória para uma struct aluno, recebe via teclado  e retorna um ponteiro para Aluno.
Aluno *recebe_dados(void);

//Função que imprime os dadas do aluno.
void imprimir(Aluno *ponteiro, int tamanho);

//Função que libera memória do main.c
void liberar(Aluno *ponteiro);

//Função que matricula alunos.
Aluno *matricular_alunos(int max);
