//Definição de novo tipo: Aluno
typedef struct aluno Aluno;

//Função que aloca memória para uma struct aluno, recebe via teclado 
//e retorna um ponteiro para "matricular_alunos".
Aluno *recebe_dados(void);

//Função que matricula um número N de alunos.
Aluno *matricular_alunos();

//Função que imprime os dado(s) dos aluno(s).
void imprimir(Aluno *ponteiro, int tamanho);

//Função que libera memória ao fim da execução.
void liberar(Aluno *ponteiro);
