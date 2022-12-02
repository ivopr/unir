hold all

# questao 1 do slide
# f = @(x) 6 + 2 * x - x.^2
# x = [-1 2 4];
# y = [3 6 -2];

# questao 2 do slide

plot(x(1), y(1), 'r*', 'linewidth', 4);
plot(x(2), y(2), 'r*', 'linewidth', 4);
plot(x(3), y(3), 'r*', 'linewidth', 4);
axis([-10 10]);
x = linspace(-10,10);
plot(x,f(x));
hold off;