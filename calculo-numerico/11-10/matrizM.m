function [At, Bt] = matrizM(A, B)
  [n, ~] = size(A);
  for i = 1:n
    B(i) = B(i) / A(i,i);
    A(i,:) = A(i,:) / A(i,i);
  endfor

  At = A - eye(size(A));
  At = -At;
  Bt = B;
endfunction
