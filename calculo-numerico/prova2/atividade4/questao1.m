# A = [ 10, 2, 1; 1, 5, 1; 2, 3, 10 ];
# B = [ 7; -8; 6 ];
# x0 = [ 0.7; -1.6; 0.6 ];
# tol = 5e-2;

# A Matriz M é formada pela subtração da Matriz A pela Matriz Diagonal de A 

## IT 1
### M = [ 0 2 1; 1 0 1; 2 3 0 ];
### x = D \ (B - M * x0) = [ 0.9600; -1.8600; 0.9400 ];
### er = max(abs(x - x0) / max(abs(x))) = 0.1828
### x0 = x;
### er > tol? Sim, então podemos continuar

## IT 2
### M = [ 0 2 1; 1 0 1; 2 3 0 ];
### x = D \ (B - M * x0) = [ 0.9780; -1.9800; 0.9660 ];
### er = max(abs(x - x0) / max(abs(x))) = 0.060606
### x0 = x;
### er > tol? Sim, então podemos continuar

## IT FINAL
### x = D \ (B - M * x0) = [ 0.9994; -1.9888; 0.9984 ];
### er = max(abs(x - x0) / max(abs(x))) = 0.016291
### er > tol? Não, então finalizamos o programa

function [x k] = questao1(A, B, x0, tol, kMax)
  D = diag(diag(A));
  M = A - D
  k = 0;
  er = 1;
  x = zeros(size(x0));

  while(k < kMax)
    x = D \ (B - M * x0)
    er = max(abs(x - x0) / max(abs(x)))
    k = k + 1
    x0 = x;

    if(er < tol)
      return
    endif
  endwhile
  error("Método falhou em %d iterações", k);
endfunction
