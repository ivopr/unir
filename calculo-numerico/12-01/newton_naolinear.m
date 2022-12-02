function [k, x] = newton_naolinear(x0, tol, kMax)
  k = 0;
  er = 1;
  while(k <= kMax)
    k = k + 1;
    s = -J_x(x0) \ F_x(x0);
    x = x0 + s;
    er = max(abs(x - x0)) / max(abs(x));
    if(er < tol)
      disp(x)
      return;
    endif
    x0 = x;
  endwhile
  error("O método falhou em %d iterações\n", k);
endfunction