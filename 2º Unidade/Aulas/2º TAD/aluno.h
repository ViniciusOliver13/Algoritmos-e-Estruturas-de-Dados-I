//Defini��o de novo tipo: Aluno
typedef struct aluno Aluno;

//Fun��o que aloca mem�ria para uma struct aluno, recebe via teclado  e retorna um ponteiro para Aluno.
Aluno *recebe_dados(void);

//Fun��o que imprime os dadas do aluno.
void imprimir(Aluno *ponteiro, int tamanho);

//Fun��o que libera mem�ria do main.c
void liberar(Aluno *ponteiro);

//Fun��o que matricula alunos.
Aluno *matricular_alunos(int max);
