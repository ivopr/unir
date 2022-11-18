# Construa no Octave a matriz quadrada A de ordem n, tal que aij = i + j. Construa
# cada uma das matrizes descritas abaixo.

# a. B é a matriz que contém apenas as linhas pares de A;
# b. C é a matriz que contém apenas as colunas ímpares de A.
# c. D é uma submatriz quadrada de ordem k formada apenas pelas primeiras k
# linhas e colunas de A (a matriz quadrada de ordem k que fica no “canto
# superior” de A).
# d. E é formada a partir de A retirando-se uma borda de largura k, ou seja, sem
# as primeiras e últimas k linhas e colunas.


n = 4;

A = zeros(n);
B = [];
C = [];
[lin, col] = size(A);

for i = 1 : lin
  for j = 1 : col
    A(i, j) = i + j;
  endfor
  if (mod(i, 2) == 0)
    B = [B; A(i, :)];
  endif
  if (mod(i, 2) == 1)
    C = [C A(:, i)];
  endif
endfor

K = 1;
D = A(1:K, 1:K);
E = A(K+1:end - K, K+1:end - K);

