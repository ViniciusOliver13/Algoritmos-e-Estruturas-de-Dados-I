typedef struct contabancaria ContaBancaria;

//Aloca memória para cada nova conta criada.
ContaBancaria *CriarConta(char *nome, int num, float valor);

//Faz um deposito de um determinado valor em uma conta.
void Deposita(ContaBancaria *p, int num);

//Realiza um saque em uma conta e verifica se tem saldo suficiente para o saque.
void Saca(ContaBancaria *clientes, int tam);

//Realiza uma transferência de uma conta para outra.
void Transfere(ContaBancaria *clientes, int tam);

//Mostra o saldo disponível em uma conta.
void Saldo(ContaBancaria *clientes, int tam);

//Libera a memória alocado da execução do programa.
void ExcluiConta(ContaBancaria *clientes);

//Mostra as informações de todas as pessoas cadastradas: nome, número da conta e saldo. 
void verClientes(ContaBancaria *clientes, int tam); 
