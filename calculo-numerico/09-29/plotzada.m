g = @(x) x .^ 3;
h = @(x) 9 * x - 3;

x = linspace(-4, 4);

plot(x, g(x));
hold all
plot(x, h(x));
hold off

