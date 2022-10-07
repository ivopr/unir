#include <stdio.h>
#include <stdlib.h>
  int busca(int vetor1[10], int num) {
    // declaração de variáveis
    int k = -1, i;
    for(i = 0; i < 10; i++) {
      // se o valor do indice i do vetor1 for igual a num, o valor de k será alterado pra 0
      // se for diferente, não há alteração
      if(vetor1[i] == num) {
        k = 0;
      }//if
    }//for
    //retorna o valor de k para a função intersec (sempre vai ser 0 ou -1)
    return k;
  }//função

  // como a professora já explicou, não precisa retornar o vetor, então isso aqui ficou em void, porque NÃO PRECISA RETORNAR NADA PRO MAIN.
  void intersec(int vetor[10], int vetor1[10]) {
    // declarar variáveis que serão usadas aqui, nessa função. SÓ AQUI.
    int num, i, k;
    for(i = 0; i < 10; i++) {
      // num agora tem o mesmo valor de vetor[i]
      num = vetor[i];
      // a variável k vai receber o que vai retornar na busca (sempre vai ser 0 ou -1)
      // os valores de retorno significam:
      // 0 = o número que está na variável num faz parte da intersecção entre os dois vetores
      // -1 = o número que está na variável num não faz parte da intersecção entre os dois vetores
      k = busca(vetor1, num);
      // verifica se o valor que retornou para a variável k é diferente de -1
      // se for diferente de -1 ele exibe o valor que está na variável num, pois o mesmo é parte da intersecção
      // caso o número que está na variável num não faça parte da intersecção, não vai fazer nada
      if(k != -1) {
        printf("%.3d ", num);
      }//if k != -1
    }//for i
    // pula uma linha pra separar os valores da intersecção da mensagem de pressionar uma tecla para encerrar o programa
    printf("\n");
  }//função

  int main() {
    // declaração de variáveis, bem simples.
    int vetor[10], vetor1[10], i;

    // leitura dos vetores do vetor[10]
    for(i = 0; i < 10; i++) {
      printf("Vetor X[%d]: ", i);
      scanf("%d", &vetor[i]);
      system("clear");
    }//for vetor[10]

    // sim, pode usar a mesma variável i pra dois for distintos, como a variável é zerada ao declarar o for (i = 0).
    // leitura dos valores do vetor1[10]
    for(i = 0; i < 10; i++) {
      printf("Vetor Y[%d]: ", i);
      scanf("%d", &vetor1[i]);
      system("clear");
    }//for vetor1[10]

    // envia os dois vetores pra função, lembrando que, pra enviar não precisa definir o tamanho aqui, ele vai completo.
    // como a função é void, não há por que guardar o 'retorno' em algum lugar, pois não há retorno.
    intersec(vetor, vetor1);

    return 0;
  }//main
