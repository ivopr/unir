# func = @(x) x^3 -5 * x - 5;
# g = @(x) sqrt(6 - x);
# er = 1e-3;
# x0 = 3;

# Iteração 1
# x = g(x0) = 1.7321;
# x - x0 = -1.2679; Não é menor que er, continua
# func(x) = -9.3012; Não é igual a 0, continua.
# x0 = x;

# Iteração 2
# x = g(x0) = 3.9117;
# x - x0 = 13.213; Não é menor que er, continua
# func(x) = 35.296; Não é igual a 0, continua.
# x0 = x;

function [x, k] = questao3(func, g, x, tol, n)
	k = 1;
	x0 = x;
	while(k <= n)
		x = g(x0);
		if (abs(x - x0) < tol || func(x) == 0)
			return
		endif
		x0 = x;
		k += 1;
	endwhile
endfunction
