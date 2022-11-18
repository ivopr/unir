function [x k] = jacobi2i(A, B, x0, tol, kMax)
  [n, ~] = size(A);
  [A, B] = matrizM(A, B);

  x = [];
  k = 0;
  er = 1;
  while(k <= kMax)
    k = k + 1;
    x = A * x0 + B;
    er = max(abs(x - x0) / max(abs(x)));
    x0 = x;

    if (er < tol)
      return
    endif
  endwhile
  error("Método falhou em %d iterações", k);
endfunction
