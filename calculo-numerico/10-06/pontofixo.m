# func = @(x) x^2 + x - 6;
# g = @(x) 6 - x ^ 2;
# g = @(x) sqrt(6 - x);

function [x, k] = pontofixo(func, g, x, tol, n)
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
