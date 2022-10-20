# func = @(x) (x.^2 / 5) - 2 * x - 3;
# pos = [9, 10]; [a, b]
# p = 1e-3;
# er = 1;
# x = a;

# Iteração 1
# er > p;
# xa = x;
# x = 9 - (func(9) * (10 - 9)) / (func(10) - func(9)) = 11.667;
# func(x) * func(a) = -4.2709; É menor que 0, então
# b = x;
# er = 11.667 - 9 / 11.667 = 0.2286;

# Iteração 2
# er > p;
# xa = x;
# x = 9 - (func(9) * (11.667 - 9)) / (func(11.667) - func(9)) = 11.250;
# func(x) * func(a) = 0.9000; É maior que 0, então
# a = x;
# er = 11.250 - 9 / 11.250 = 0.2000;

function [x, cont] = questao2(func, pos, p, n)
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
