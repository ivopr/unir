figure
hold all
# questao 1-a
f = @(x) 255 + (-329 * x) + (154 * x.^2) + (-30 * x.^3) + (2 * x.^4)
x = [1 2 4 5 7];
y = [52 5 -5 -40 10];

plot(x(1), y(1), 'r*', 'linewidth', 4);
plot(x(2), y(2), 'r*', 'linewidth', 4);
plot(x(3), y(3), 'r*', 'linewidth', 4);
plot(x(4), y(4), 'r*', 'linewidth', 4);
plot(x(5), y(5), 'r*', 'linewidth', 4);
axis([-10 10]);
x = linspace(-10,10);
plot(x,f(x));
title("Questão 1-a")
hold off;




figure
hold all
# questao 2
f = @(x) 2/3 * x.^2 - 7/3 * x + 1
x = [-1 0 2];
y = [4 1 -1];

plot(x(1), y(1), 'r*', 'linewidth', 4);
plot(x(2), y(2), 'r*', 'linewidth', 4);
plot(x(3), y(3), 'r*', 'linewidth', 4);
axis([-10 10]);
x = linspace(-10,10);
plot(x,f(x));
title("Questão 2")
hold off;