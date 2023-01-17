# Carregando o pacote necessario
pkg load symbolic

# definindo as variaveis
syms x y;

# definindo a função
f1 = -x + y^2;
f2 = x^2+5*y^2-6;



matlabFunction(diff(f1, x))
matlabFunction(diff(f1, y))

matlabFunction(diff(f2, x))
matlabFunction(diff(f2, y))