# Questão 2

printf("Letra A)\nMenor = 0.1000 . 10^-5\nMaior = 0.9999 . 10^5\n")

arredondamento = 0.7376; % arredonda do 8
truncamento = 0.7375;
printf("\nLetra B)\nround = %.2f . 10^2\nfloor = %.3f . 10^2\n", arredondamento, truncamento)

a = 0.4245; % 10^5
b = 0.00003; % 10^5

printf("\nLetra C)\na + b = %f . 10^5\n", a + b)


x = 0.4245; % 10^5
y = 0.00003; % 10^5
[l c] = size(y(abs(y) > 1e-4));
if l == 0
    y = 0;
end
soma = x + y;
for i=1:10
  soma += y;
endfor


printf("\nLetra D\n");
x = 0.3; % 10^1
y = 0.4245; % 10^5
soma = 0;
for i=1:10
  soma += x;
  if soma == 1.2
    soma = 0.12;
    x = 0.03;
  endif
endfor

soma = soma * 10^(-3)

printf("\nLetra E) 𝑆 = %.4f\n", soma + y)
