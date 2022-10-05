#func = @(x) x .^ 3 - 30 * x .^ 2 + 2552;
#dfunc = @(x) 3 * x .^ 2 - 60 * x;

function [x, k] = newton(func, dfunc, x, tol, kmax)
	for k = 1 : kmax
		dx = func(x) / dfunc(x);
		printf("%f, %f\n", dx, x);
		if (abs(dx) < tol)
			return
		endif
		x = x - dx;
	endfor
	x = NaN;
endfunction
