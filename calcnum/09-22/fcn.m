function [it, x] = fcn(a, b, N, t)
	F = @(x) x .^ 3 - 30 * x .^ 2 + 2552;
	i = 0;
	for i = 0 : N
		x = (a + b) / 2;
		fx = F(x);
		fa = F(a);

		if(fx == 0 || (b - a) / 2 <= t)
			printf("Iteração %d\nX = %f\n", i, x);
			return
		else
			if(fa * fx < 0)
				b = x;
			else
				a = x;
			endif
		endif
	endfor

	printf("Método falhou em %d iterações\n", i);
endfunction
