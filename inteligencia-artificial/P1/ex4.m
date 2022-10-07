clc;
clearvars;

x = -6:0.01:6;

y = 1 ./ (1.0 + exp(-0.5 * x));
subplot(2, 2, 1)
plot(x, y, 'linew', 0.1)
xlabel('b = 0.5')

y = 1 ./ (1.0 + exp(-1.0 * x));
subplot(2, 2, 2)
plot(x, y, 'linew', 0.1)
xlabel('b = 1.0')

y = 1 ./ (1.0 + exp(-5.0 * x));
subplot(2, 2, 3)
plot(x, y, 'linew', 0.1)
xlabel('b = 5.0')

y = 1 ./ (1.0 + exp(-20 * x));
subplot(2, 2, 4)
plot(x, y, 'linew', 0.1)
xlabel('b = 20')