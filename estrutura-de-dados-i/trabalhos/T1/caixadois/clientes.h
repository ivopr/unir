#pragma once
constexpr auto MAX = 50;
#define cleanbuffer fseek(stdin, 0, SEEK_END)
#define lista c cliente[MAX]

typedef struct
{
	int codigo = 0;
	char tipo = 'N', origem[5], destino[5];
	float valor = 0;
}t;

typedef struct
{
	char numero[5] = "NNNN";
	float saldo = 0;
	t transacao[MAX];
	int topo = -1;
}cc;

typedef struct
{
	int codigo = 0;
	char nome[50], telefone[20];
	cc conta;
}c;

/* transações */
bool deposito(lista, cc* destino, float valor); // deposita a quantia inserida em uma conta corrente;
bool saque(lista, cc* origem, float valor); // saca a quantia inserida de uma conta corrente (apenas se o saldo for suficiente);
bool transferencia(lista, cc* origem, cc* destino, float valor); // transfere a quantia inserida de uma conta corrente para outra (se a conta corrente a ser sacada não possuir saldo, a operação é cancelada);

/* criação de conta corrente */
cc gerarContaCliente(lista); // gera e retorna uma nova conta corrente. impede duplicatas usando a função contaExiste;
bool contaExiste(lista, char* numero); // verifica se o numero aleatório criado para a conta já existe. se sim, retorna true, se não, false;

/* adicionar cliente */
bool adicionarCliente(lista); // cria um novo cliente ao inserir nome e telefone, com todo o resto aleatório ou em branco (lista de transações);
int gerarCodigoCliente(lista); // gera e verifica um código aleatório para um novo cliente. impede duplicatas usando a função clienteExiste;
int posLivre(lista); // retorna a ultima posição vazia, se não houver uma, retorna -1;
bool clienteExiste(lista, int codigo); // verifica se já existe um cliente com o código fornecido;

/* remove um cliente */
bool removerCliente(lista, int codigo); // remove um cliente da lista e a reorganiza;

/* quickSort */
void troca(c* x, c* y); // troca dois clientes de posição. cliente y vai para a posição de cliente x e vice-versa;
int particao(lista, int inicio, int fim); // verifica e chama a função de troca em uma partição da lista;
void quickSort(lista, int inicio, int fim); // inicia o particionamento da lista de clientes para a ordenação;

/* retorna um cliente */
c* retornaCliente(lista, int codigo); // retorna todas as informações de um cliente; em ponteiro mesmo as vezes não sendo para modificação de dados;

/* atualiza as informações de um cliente */
void atualizarCliente(lista, c* base); // atualiza o cadastro de um cliente (sem forçar a inserção de um dos dois camos), caso não queira atualizar, basta inserir N || n;

/* exibe todos os clientes cadastrados */
void exibeTodosClientes(lista); // exibe todos os clientes presentes na lista;

/* pra deixar bonitinho */
void limpar(); // limpa o console... eu chamaria de coca-cola mas provavelmente perderia ponto...
void parar(); // "pausa" o programa até a inserção de algo;
void pararEsp(); // faz o mesmo que o anterior, porém como o anterior tem limpeza de buffer, por conta de uma magia das trevas quando há a entrada de uma string ele simplesmente não para, então esse aqui não limpa o buffer e para;