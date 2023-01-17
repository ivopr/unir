# A = [ 5 1 1; 3 4 1; 3 3 6 ];
# B = [ 5; 6; 0 ];
# x0 = [ 0; 0; 0 ];
# tol = 5e-2;

# L = [ 5 0 0; 3 4 0; 3 3 6 ];
# U = [ 0 1 1; 0 0 1; 0 0 0 ];

## IT 1
### x = L \ (B - (U * x0)) = [ 1.0000; 0.7500; -0.8750 ];
### er = max(abs(x - x0) / max(abs(x))) = 1;
### x0 = x
### er > tol? Sim então podemos continuar

## IT 2
### x = L \ (B - (U * x0)) = [ 1.0250; 0.9500; -0.9875 ]
### er = max(abs(x - x0) / max(abs(x))) = 0.1951
### x0 = x
### er > tol? Sim então podemos continuar

## IT FINAL
### x = L \ (B - (U * x0)) = [ 1.0075; 0.9913; -0.9994 ]
### er = max(abs(x - x0) / max(abs(x))) = 0.040943
### er > tol? Não, não podemos continuar

## x = [ 1.0075; 0.9913; -0.9994 ]
## k = 3

function [x k] = questao2(A, B, x0, tol, kmax)
  L = tril(A)
  U = A - L
  k = 0;
  er = tol + 1;

  while(k <= kmax)
    k = k + 1
    x = L \ (B - (U * x0))
    er = max(abs(x - x0) / max(abs(x)))
    x0 = x;

    if(tol > er)
      return
    endif
  endwhile
  error("O método falhou em %d iterações", k)
endfunction