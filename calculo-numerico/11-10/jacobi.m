function [x, k] = jacobi(A, B, x0, tol, kMax)
  D = diag(diag(A));
  M = A - D;
  k = 0;
  er = 1;
  x = zeros(size(x0));

  while (k < kMax)
    x = D \ (B - M * x0);
    printf("Valor de X: %f\n", x);
    er = max(abs(x - x0) / max(abs(x)));
    k = k + 1;
    x0 = x;

    if (er < tol)
      return
    endif
  endwhile
  error("Método falhou em %d iterações", k);
endfunction
