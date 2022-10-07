void Prog::heapSort()
{
	int i = tf / 2, n = tf, pai, filho, t;
   while(true) {
      if (i > 0) {
          i--;
          t = vetor[i];
      } else {
          n--;
          if (n <= 0) return;
          t = vetor[n];
          vetor[n] = vetor[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (vetor[filho + 1] > vetor[filho]))
              filho++;
          if (vetor[filho] > t) {
             vetor[pai] = vetor[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      vetor[pai] = t;
  }
}