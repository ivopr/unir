# Questao 3
hold all
x = [1; 2; 3; 4; 5; 6; 7];
y = [0.5; 2.5; 2; 4; 3.5; 6; 5.5];
f = @(x) 0.071429 + 0.8393 * x;

plot(x(1),y(1),'r','linewidth',4);
plot(x(2),y(2),'r','linewidth',4);
plot(x(3),y(3),'r','linewidth',4);
plot(x(4),y(4),'r','linewidth',4);
plot(x(5),y(5),'r','linewidth',4);
plot(x(6),y(6),'r','linewidth',4);
plot(x(7),y(7),'r','linewidth',4);

axis([0 10]);
x = linspace(0, 10);
plot(x,f(x));
hold off
