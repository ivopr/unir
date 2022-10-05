# Questão 8


function [x, k] = questao8(x, tol, kmax)
	func = @(x) x .^ 3 - 2 * x .^ 2 + 3 * x + 10;
	dfunc = @(x) 3 * x .^ 2 - 4 * x + 3;

	for k = 1 : kmax
		dx = func(x) / dfunc(x);
		if (abs(dx) < tol)
			return
		endif
		x = x - dx;
	endfor
	x = NaN;
endfunction
