# Questao 7

function [i, x] = questao7(a, b, N, t)
	F = @(x) x .^ 3 - 2 * x .^ 2 + 3 * x + 10; % função anonima

	exes = linspace(-10, 10);
	plot(exes, F(exes));

	i = 0;
	for i = 0 : N
		x = (a + b) / 2;
		fx = F(x);
		fa = F(a);

		if(fx == 0 || (b - a) / 2 <= t)
			printf("Iteração %d\nX = %f\n", i + 1, x);
			return
		else
			if(fa * fx < 0)
				b = x;
			else
				a = x;
			endif
		endif
	endfor

	printf("Método falhou em %d iterações\n", i + 1);
endfunction
