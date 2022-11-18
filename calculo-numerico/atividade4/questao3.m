# F = @(x) [ x(1)^2 + x(2)^2 - 9; x(1)^2 - 4 * x(2) ];
# J = @(x) [ 2 * x(1), 2 * x(2); 2 * x(1), -4 ];
# tols = [ 1e-5 1e-3 ];
# x = [ 2; 1 ];

### Fx = F(x) = [ -4; 0 ]
### Dr = norm(tols(1) + 1, Inf) = 1.0000

## IT 1
### s = -J(x) \ Fx = [ 0.6667; 0.6667 ]
### x = x + s = [ 2.6667; 1.6667 ]
### Dr = norm(s) = 0.9428
### Fx = F(x) = [ 0.8889; 0.4444 ]
### norm(Fx, Inf) = 4
### Dr > 1e-5? Sim. E norm(Fx, Inf) > 1e-3? Sim, então podemos continuar

## IT 2
### s = -J(x) \ Fx = [ -0.128788; -0.060606 ]
### x = x + s = [ 2.5379; 1.6061 ]
### Dr = norm(s) = 0.1423
### Fx = F(x) = [ 0.020259; 0.016586 ]
### norm(Fx, Inf) = 0.8889
### Dr > 1e-5? Sim. E norm(Fx, Inf) > 1e-3? Sim, então podemos continuar

## IT FINAL
### s = -J(x) \ Fx = [ -0.0036; -0.0005 ]
### x = x + s = [ 2.5342; 1.6056 ]
### Dr = norm(s) = 0.0037
### norm(Fx, Inf) = 0.020259
### Dr > 1e-5? Não. Então não podemos continuar

## x = [ 2.5342; 1.6056 ]
## k = 3

function [x k] = questao3(F, J, x, tols, kMax)
  k = 0;
  Fx = F(x);
  Dr = norm(tols(1) + 1, Inf);

  while k <= kMax && norm(Fx, Inf) > tols(2) && Dr > tols(1)
    k = k + 1;
    s = -J(x) \ Fx;
    x = x + s;
    Dr = norm(s);
    Fx = F(x);
  endwhile
end
