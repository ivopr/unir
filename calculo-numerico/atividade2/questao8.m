# Questão 8
%{
Aplique o método de Newton-Raphson à equação
𝑥 Justifique o que acontece. 3 − 2𝑥
2
+ 3𝑥 + 10 = 0 𝑐𝑜𝑚 𝑥
0 = 1, 9
%}

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
