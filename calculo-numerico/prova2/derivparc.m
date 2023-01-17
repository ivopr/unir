# Carregando o pacote necessario
pkg load symbolic

# definindo as variaveis
syms x y;

# definindo a função
f = x^2 - 4*x + 4*y;

# derivando a função f em relação a x
diff(f, x)

# derivando a função f em relação a x
diff(f, y)

matlabFunction(diff(f, x))
matlabFunction(diff(f, y))