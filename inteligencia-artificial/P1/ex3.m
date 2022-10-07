clc;
clearvars;

x = linspace(0, (5 .* pi) ./ 2, 500);

subplot(2, 2, 1)
plot(sin(x))
xlabel('sin(x)')

subplot(2, 2, 2)
plot(cos(x))
xlabel('cos(x)')

subplot(2, 2, 3)
plot(2 .* sin(x) .* cos(x))
xlabel('2 * sin(x) * cos(x)')

subplot(2, 2, 4)
plot(sin(x) ./ exp(x))
xlabel('sin(x) / exp(x)')