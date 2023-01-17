# Questao 7
x = [1.6; 5.17; 6; 13];
y = [2.9; 5.37; 8; 2];

V = [x.^2 x x.^0];
a = V\y;

f = @(x) a(1) + a(2) * x + a(3) * x^2;
xx = linspace(-10,20);
plot(x,y,'ro',xx,polyval(a,xx),'b-');grid on