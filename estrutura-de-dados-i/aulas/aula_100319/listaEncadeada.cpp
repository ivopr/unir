#include "listaEncadeada.hpp"

void iniciar(lista *a)
{
  a->inicio = -1;
  a->inicioDisponivel = 0;
  for(int i = 0; i < MAX; i++)
    a->vetor[i].proximo = i + 1;
  a->vetor[MAX - 1].proximo = -1;
}

void destruir(lista *a)
{
  iniciar(a);
}

void exibir(lista *a)
{
  for(int i = a->inicio; i != -1; i = a->vetor[i].proximo)
    printf("vetor[%d]: %d\n", i, a->vetor[i].info.chave);
}
/*
void copia(lista *a, lista *b)
{

}

void inverter(lista *a, lista *b)
{

}

void intercala(lista *a, lista *b, lista *c)
{

}

void contElem(lista *a, lista *b)
{

}

void exibirCont(lista *a)
{

}
*/
int tamanho(lista *a)
{
  int cont, i;
  for(i = a->inicio, cont = 0; i != -1; cont++, i = a->vetor[i].proximo);
  return cont;
}

int inserirInicio(lista *a, elemento c)
{
  if(listaCheia(a)) return 0;
  int pos = a->inicioDisponivel;
  a->inicioDisponivel = a->vetor[pos].proximo;
  a->vetor[pos].info = c;
  a->vetor[pos].proximo = a->inicio;
  a->inicio = pos;
  return 1;
}

int inserirFim(lista *a, elemento c)
{
  if(listaCheia(a)) return 0;
  if(listaVazia(a)) return inserirInicio(a, c);
  int pos = a->inicio;
  while(a->vetor[pos].proximo != -1)
  {
    a->vetor[pos].proximo;
  }
  a->vetor[pos].proximo = a->inicioDisponivel;
  a->inicioDisponivel = a->vetor[a->inicioDisponivel].proximo;
  pos = a->vetor[pos].proximo;
  a->vetor[pos].info = c;
  a->vetor[pos].proximo = -1;
  return 1;
}

int inserirApos(lista *a, int k, elemento c)
{
  int pos = a->inicioDisponivel;
  a->inicioDisponivel = a->vetor[pos].proximo;
  a->vetor[pos].info = c;
  a->vetor[pos].proximo = a->vetor[k].proximo;
  a->vetor[k].proximo = pos;
  return 1;
}

int inserirOrdenado(lista *a, elemento c)
{
  if(listaCheia(a)) return 0;
  if(listaVazia(a)) return inserirInicio(a, c);
  int k = a->inicio, anterior = -1;
  while(k != -1 && a->vetor[k].info.chave < c.chave)
  {
    anterior = k;
    k = a->vetor[k].proximo;
  }
  if(anterior == -1)
    return inserirInicio(a, c);

  inserirApos(a, anterior, c);
  return 1;
}

int removerInicio(lista *a)
{
  if(listaVazia(a)) return 0;
  int pos = a->inicio;
  a->inicio = a->vetor[pos].proximo;
  a->vetor[pos].proximo = a->inicioDisponivel;
  a->inicioDisponivel = pos;
  return 1;
}

void removerApos(lista *a, int k)
{
  int pos = a->vetor[k].proximo;
  a->vetor[k].proximo = a->vetor[pos].proximo;
  a->vetor[pos].proximo = a->inicioDisponivel;
  a->inicioDisponivel = pos;
}

int remover(lista *a, int chave)
{
  if(listaVazia(a)) return 0;
  int anterior = -1, pos = a->inicio;
  while(pos != -1 && a->vetor[pos].info.chave != chave)
  {
    anterior = pos;
    pos = a->vetor[pos].proximo;
  }
  if(pos == -1) return 0;
  if(anterior == -1) return removerInicio(a);
  removerApos(a, anterior);
  return 1;
}

int listaVazia(const lista *a)
{
  return a->inicio == -1;
}

int listaCheia(const lista *a)
{
  return a->inicioDisponivel == -1;
}

/*
int ordenadoCrescente(lista *a)
{

}

int ordenadoDecrescente(lista *a)
{

}

int removerIndice(lista *a, int k)
{

}

int copiaNaoRepetidos(lista *a, lista *b)
{

}

int contarMaior(lista *a)
{

}

int contarMenor(lista *a)
{

}
*/
void limpar()
{
  for(int i = 0; i < 100; i++)
    printf("\n");
}

void parar()
{
	printf("pressione qualquer tecla para continuar...\n");
  std::cin.ignore();
	std::cin.get();
}