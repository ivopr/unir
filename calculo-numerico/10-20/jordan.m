function [At, bt] = jordan(A, b)
  [n, m] = size(A);
  for i=1:n
    %[A, b] = pivotParcial(A, b, i);
    for j=1:n
      if (i != j)
        fator = A(j,i)/A(i,i); % elemento a ser eliminado dividido pelo pivô!
        A(j,i) = 0;

        for (k=i+1:n)
          A(j,k) = A(j,k) - fator*A(i,k);
        endfor
        b(j) = b(j) - fator*b(i);
      endif
    endfor
  endfor
  At = A;
  bt = b;
endfunction
