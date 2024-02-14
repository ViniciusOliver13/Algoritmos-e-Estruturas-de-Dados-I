typedef struct contabancaria ContaBancaria;

//Aloca mem�ria para cada nova conta criada.
ContaBancaria *CriarConta(char *nome, int num, float valor);

//Faz um deposito de um determinado valor em uma conta.
void Deposita(ContaBancaria *p, int num);

//Realiza um saque em uma conta e verifica se tem saldo suficiente para o saque.
void Saca(ContaBancaria *clientes, int tam);

//Realiza uma transfer�ncia de uma conta para outra.
void Transfere(ContaBancaria *clientes, int tam);

//Mostra o saldo dispon�vel em uma conta.
void Saldo(ContaBancaria *clientes, int tam);

//Libera a mem�ria alocado da execu��o do programa.
void ExcluiConta(ContaBancaria *clientes);

//Mostra as informa��es de todas as pessoas cadastradas: nome, n�mero da conta e saldo. 
void verClientes(ContaBancaria *clientes, int tam); 
