x = 0:0.1:4*pi;

plot(x, sin(x), 'linewidth', 3);
hold all
plot(x, cos(x), '--', 'linewidth', 3);
plot(x, tan(x), '-.', 'linewidth', 3);
plot(x, exp(x), ':', 'linewidth', 3);
plot(x, log(x), '*', 'linewidth', 3);
axis([0,10,-2,4]);
legend('Seno', 'Cosseno', 'Tangente', 'Exponencial', 'Logaritmo');
legend('boxoff');
hold off

x = -2*pi:0.1:2*pi;
subplot(2, 1, 1)
plot(x, sin(x), '.r', 'linewidth', 3);
title('Gráfico de Sin(x)');
axis([-3*pi, 4*pi, -3, 1.5]);
xlabel('X');
ylabel('Seno de X');
subplot(2, 1, 2)
plot(x, cos(x), '-.m', 'linewidth', 3);
axis([-2.5*pi, 2.1*pi, -1.5, 2.5]);
title('Grafico de Cos(x)');
xlabel('X');
ylabel('Cosseno de X');
