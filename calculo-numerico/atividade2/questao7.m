# Questao 7
%{
Aplique o método da bisseção à equação 𝑥 . Construa o
3 − 2𝑥
2
+ 3𝑥 + 10 = 0
gráfico da função e faça a análise da variação de sinal para auxiliar na escolha do
intervalo [a, b].
%}
F = @(x) x .^ 3 - 2 * x .^ 2 + 3 * x + 10; % função anonima
exes = linspace(-10, 10);
plot(exes, F(exes));
hold on
[x] = bissecao(F, 2, 3, 20, 1e-3);
plot(x, F(x), "o");
hold off

printf("a = 2 | b = 3 | Tol = 1e^-3\n");
printf("F = x .^ 3 - 2 * x .^ 2 + 3 * x + 10\n\n");

printf("--- IT 1 ---\n");
printf("F(a) = 2 .^ 3 - 2 * 2 .^ 2 + 3 * 2 + 10 = 16\n");
printf("F(b) = 3 .^ 3 - 2 * 3 .^ 2 + 3 * 3 + 10 = 28\n\n");

printf("x = (2 + 3) / 2 = 2.5\n");
printf("F(x) = 2.5 .^ 3 - 2 * 2.5 .^ 2 + 3 * 2.5 + 10 = 20.625\n\n");

printf("F(x) > 0 e (b - a) / 2 > Tol\n");
printf("F(a) * F(x) = 320 e 320 > 0\n");
printf("a = 2.5 | b = 3\n");

printf("--- Fim IT 1 ---\n\n")

printf("--- IT 2 ---\n");
printf("F(a) = F(x) = 20.625\n");
printf("F(b) = 28\n\n");

printf("x = (a + b) / 2 = 2.75\n");
printf("F(x) = 2.75 .^ 3 - 2 * 2.75 .^ 2 + 3 * 2.75 + 10 = 23.922\n\n");

printf("F(x) > 0 e (b - a) / 2 > Tol\n");
printf("F(a) * F(x) = 492.39 e 492.39 > 0\n");
printf("a = 2.75 e b = 3\n");
printf("-- Fim IT 2 ---\n");
