hold on
% f(x) = a1 + a2*x;
f = @(x) 21.7619 + 0.5714*x;

x=[6 7 11];
y=[29 21 29];

plot(x(1),y(1),'r','linewidth',4)
plot(x(2),y(2),'r','linewidth',4)
plot(x(3),y(3),'r','linewidth',4)

axis([-10 30]);
x = linspace(-10, 50);
plot(x,f(x))
hold off