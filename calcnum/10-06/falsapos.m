# func = @(x) x.^2 - 5;
# func = @(x) x.^3 - 9 * x + 3;
# pos = [2, 3]
# p = 1e-3

function [x, cont] = falsapos(func, pos, p, n)
	cont = 0;
	er = 1;
	x = pos(1,1);

	while er > p && cont <= n
		xa = x;
		a = pos(1, 1);
		b = pos(1, 2);
		x = a - (func(a) * (b - a)) / (func(b) - func(a));
		if func(x) * func(a) < 0
			pos(1, 2) = x;
		else
			pos(1, 1) = x;
		endif
		er = abs(x - xa) / abs(x);
		printf("%f, %f\n",x, er);
		cont = cont + 1;
	endwhile
endfunction
