# Questao 7
x = [0; 1; 2; 3; 4; 5];
y = [2.1; 7.7; 13.6; 27.2; 40.9; 61.1];

V = [x.^2 x x.^0];
a = V\y;

f = @(x) a(1) + a(2) * x + a(3) * x^2;
xx = linspace(-10,20);
plot(x,y,'ro',xx,polyval(a,xx),'b-'); grid on