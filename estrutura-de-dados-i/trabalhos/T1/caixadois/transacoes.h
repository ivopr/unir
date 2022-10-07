#pragma once

/* empilha a nova transação na(s) contas alvo */
bool push(int* topoOrig, int* topoDest, t origem[MAX], t destino[MAX], t nova); // empilha uma transação nas listas de transação das contas corrente;e já existe alguma transação com o código criado aleatóriamente;

/* codigo de transação */
int gerarCodigoTransacao(lista); // gera um código de transação aleatório e verifica pela função transacaoExiste;
bool transacaoExiste(lista, int codigo); // verifica se já existe alguma transação com o código criado aleatóriamente;

/* exibe as transações de: */
void exibeTodasTransacoes(lista); // todos os clientes
void exibeTransacaoCliente(cc conta); // um cliente em específico;