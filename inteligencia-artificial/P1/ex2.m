clc;
clearvars;

x = linspace(0, 2 .* pi, 30);

figure, plot(sin(x), '-r*')

hold on

plot(cos(x), ':go')

axis ij