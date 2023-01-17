figure
hold all
# questao 1-a
f = @(x) x - 20/3;
x = [2 4 7];
y = [5 -5 10];

plot(x(1), y(1), 'r*', 'linewidth', 4);
plot(x(2), y(2), 'r*', 'linewidth', 4);
plot(x(3), y(3), 'r*', 'linewidth', 4);
axis([-10 200]);
x = linspace(-10,200);
plot(x,f(x));
title("Questão 1-a")
hold off;




# figure
# hold all
# # questao 2
# f = @(x) 2/3 * x.^2 - 7/3 * x + 1
# x = [-1 0 2];
# y = [4 1 -1];

# plot(x(1), y(1), 'r*', 'linewidth', 4);
# plot(x(2), y(2), 'r*', 'linewidth', 4);
# plot(x(3), y(3), 'r*', 'linewidth', 4);
# axis([-10 10]);
# x = linspace(-10,10);
# plot(x,f(x));
# title("Questão 2")
# hold off;