#pragma once

/* empilha a nova transa��o na(s) contas alvo */
bool push(int* topoOrig, int* topoDest, t origem[MAX], t destino[MAX], t nova); // empilha uma transa��o nas listas de transa��o das contas corrente;e j� existe alguma transa��o com o c�digo criado aleat�riamente;

/* codigo de transa��o */
int gerarCodigoTransacao(lista); // gera um c�digo de transa��o aleat�rio e verifica pela fun��o transacaoExiste;
bool transacaoExiste(lista, int codigo); // verifica se j� existe alguma transa��o com o c�digo criado aleat�riamente;

/* exibe as transa��es de: */
void exibeTodasTransacoes(lista); // todos os clientes
void exibeTransacaoCliente(cc conta); // um cliente em espec�fico;