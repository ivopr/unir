# Construa no Octave uma matriz quadrada A de ordem 10 conforme o exemplo
# abaixo. A matriz A deve conter 2 na diagonal principal e 3 na diagonal superior.
# Sua solução também funcionaria bem para matrizes de ordem bem maior, por
# exemplo, de ordem 10.000?

A = zeros(15);
[lin, col] = size(A);

for i = 1 : lin
  for j = 1 : col
    if(i == j)
      A(i, j) = 2;
    elseif((j > i) && (j - i) == 1)
      A(i,j) = 3;
    endif
  endfor
endfor
