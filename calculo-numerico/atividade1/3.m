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

