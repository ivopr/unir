# A = [ 5 1 1; 3 4 1; 3 3 6 ];
# B = [ 5; 6; 0 ];
# x0 = [ 0; 0; 0; 0 ];
# tol = 5e-2;

function [x k] = questao4(A, B, x0, tol, kmax)
  L = tril(A);
  U = A - L;
  k = 0;
  er = tol + 1;

  while(k <= kmax)
    k = k + 1;
    x = L \ (B - (U * x0));
    er = max(abs(x - x0) / max(abs(x)));
    x0 = x;

    if(tol > er)
      return
    endif
  endwhile
  error("O método falhou em %d iterações", k)
endfunction
