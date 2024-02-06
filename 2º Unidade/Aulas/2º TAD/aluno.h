//Defini��o de novo tipo: Aluno
typedef struct aluno Aluno;

//Fun��o que aloca mem�ria para uma struct aluno, recebe via teclado 
//e retorna um ponteiro para Aluno.
Aluno *recebe_dados(void);

//Fun��o que imprime os dado(s) dos aluno(s).
void imprimir(Aluno *ponteiro, int tamanho);

//Fun��o que libera mem�ria ao fim da execu��o.
void liberar(Aluno *ponteiro);

//Fun��o que matricula um determinado n�mero de alunos.
Aluno *matricular_alunos(int max);
