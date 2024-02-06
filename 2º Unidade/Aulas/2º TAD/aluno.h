//Definição de novo tipo: Aluno
typedef struct aluno Aluno;

//Função que aloca memória para uma struct aluno, recebe dados via teclado 
//e retorna um ponteiro para Aluno.
Aluno *recebe_dados(void);

//Função que matricula um determinado número de alunos escolhido pelo usuário.
Aluno *matricular_alunos(int max);

//Função que imprime os dado(s) dos aluno(s).
void imprimir(Aluno *ponteiro, int tamanho);

//Função que libera memória ao fim da execução.
void liberar(Aluno *ponteiro);

