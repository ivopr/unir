# Questão 6

function cont = questao6(a, b, N)
	func = @(x) x .^ 3 - 9 * x + 3;

	cont = 0;
	while(a <= b)
		if((func(a) * func(b)) < 0)
			cont += 1;
		endif
		a += N;
	endwhile
endfunction
