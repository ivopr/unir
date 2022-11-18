%{
A partir da equação f(x) = 0, obtenha a equação equivalente g(x) = h(x),
esboce os gráficos das funções f(x) e h(x) no mesmo eixo cartesiano e
localize os pontos x onde as duas curvas se interceptam, pois neste caso
f(𝜉) = 0 ⇔ g(𝜉) = h(𝜉). Use o Octave.
a. 𝑓(𝑥) = 𝑥 − 5
𝑥
b. 𝑓(𝑥) = 2𝑥
2
+ 4𝑥 − 6
%}

# A
funcA = @(x) sqrt(x) - 5 .^ x;
gA = @(x) sqrt(x);
hA = @(x) 5 .^ x;

x = linspace(-50, 50);

figure
plot(x, gA(x));
hold on;
plot(x, hA(x));
legend("gA(x)", "hA(x)");

# B
funcB = @(x) 2 * x .^ 2 + 4 * x - 6;
gB = @(x) 2 * x .^ 2;
hB = @(x) - 4 * x + 6;

figure
plot(x, gB(x));
hold on;
plot(x, hB(x));
legend("gB(x)", "hB(x)");
