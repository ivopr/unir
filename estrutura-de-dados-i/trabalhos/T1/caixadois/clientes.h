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

/* transa��es */
bool deposito(lista, cc* destino, float valor); // deposita a quantia inserida em uma conta corrente;
bool saque(lista, cc* origem, float valor); // saca a quantia inserida de uma conta corrente (apenas se o saldo for suficiente);
bool transferencia(lista, cc* origem, cc* destino, float valor); // transfere a quantia inserida de uma conta corrente para outra (se a conta corrente a ser sacada n�o possuir saldo, a opera��o � cancelada);

/* cria��o de conta corrente */
cc gerarContaCliente(lista); // gera e retorna uma nova conta corrente. impede duplicatas usando a fun��o contaExiste;
bool contaExiste(lista, char* numero); // verifica se o numero aleat�rio criado para a conta j� existe. se sim, retorna true, se n�o, false;

/* adicionar cliente */
bool adicionarCliente(lista); // cria um novo cliente ao inserir nome e telefone, com todo o resto aleat�rio ou em branco (lista de transa��es);
int gerarCodigoCliente(lista); // gera e verifica um c�digo aleat�rio para um novo cliente. impede duplicatas usando a fun��o clienteExiste;
int posLivre(lista); // retorna a ultima posi��o vazia, se n�o houver uma, retorna -1;
bool clienteExiste(lista, int codigo); // verifica se j� existe um cliente com o c�digo fornecido;

/* remove um cliente */
bool removerCliente(lista, int codigo); // remove um cliente da lista e a reorganiza;

/* quickSort */
void troca(c* x, c* y); // troca dois clientes de posi��o. cliente y vai para a posi��o de cliente x e vice-versa;
int particao(lista, int inicio, int fim); // verifica e chama a fun��o de troca em uma parti��o da lista;
void quickSort(lista, int inicio, int fim); // inicia o particionamento da lista de clientes para a ordena��o;

/* retorna um cliente */
c* retornaCliente(lista, int codigo); // retorna todas as informa��es de um cliente; em ponteiro mesmo as vezes n�o sendo para modifica��o de dados;

/* atualiza as informa��es de um cliente */
void atualizarCliente(lista, c* base); // atualiza o cadastro de um cliente (sem for�ar a inser��o de um dos dois camos), caso n�o queira atualizar, basta inserir N || n;

/* exibe todos os clientes cadastrados */
void exibeTodosClientes(lista); // exibe todos os clientes presentes na lista;

/* pra deixar bonitinho */
void limpar(); // limpa o console... eu chamaria de coca-cola mas provavelmente perderia ponto...
void parar(); // "pausa" o programa at� a inser��o de algo;
void pararEsp(); // faz o mesmo que o anterior, por�m como o anterior tem limpeza de buffer, por conta de uma magia das trevas quando h� a entrada de uma string ele simplesmente n�o para, ent�o esse aqui n�o limpa o buffer e para;