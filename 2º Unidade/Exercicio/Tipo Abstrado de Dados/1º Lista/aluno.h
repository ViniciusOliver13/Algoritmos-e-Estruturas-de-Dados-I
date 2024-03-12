typedef struct aluno Aluno;

Aluno* cria_aluno(char nome[], int matricula);

void matricula_disciplina(Aluno* aluno, Disciplina *disciplina);

void exclui_aluno(Aluno* aluno);

//void exibe_alunos_matriculados(Aluno** alunos, int num_alunos);