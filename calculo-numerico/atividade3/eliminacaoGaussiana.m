function [At, bt] = eliminacaoGaussiana(A, b)
  [n, ~] = size(A);
  for i=1:n-1
    [A, b] = pivotParcial(A,b,i);
    for j=i+1:n
      fator = A(j,i)/A(i,i);
      A(j,i) = 0;
      for k=i+1:n
        A(j,k) = A(j,k) - fator * A(i,k);
      endfor
      b(j) = b(j) - fator * b(i);
    endfor
  endfor
  At = A;
  bt = b;
endfunction
