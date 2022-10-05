subplot (3, 1, 1)
fplot(@(x)-3*x.^3 +7*x.^2 - 5,[0 2]);

subplot (3, 1, 2)
fplot(@(x)cos(x) / sqrt(x^2+1),[0 20]);

subplot (3, 1, 3)
fplot(@(x)exp(3*x) - exp(-3*x),[-1 1]);