# Questão 5
%{
Localize graficamente as raízes das equações a seguir:
a. 4 × 𝑐𝑜𝑠(𝑥) − 𝑒
2𝑥 = 0
b. 𝑥
2 − 𝑡𝑔(𝑥) = 0
c. 1 − 𝑥 × 𝑙𝑛(𝑥) = 0
d. 2
𝑥 − 3𝑥 = 0
e. 𝑥
3
+ 𝑥 − 1000 = 0
%}
Fa = @(x) 4 * cos(x) - e .^ (2 * x);
Fb = @(x) (x / 2) -  tan(x);
Fc = @(x) 1 - x .* log(x);
Fd = @(x) 2 .^ x - 3 * x;
Fe = @(x) x .^ 3 + x - 1000;

y = linspace(1, 4);

subplot(3, 2, 1);
plot(y, Fa(y));
[i, xa] = bissecao(Fa, 2, 3, 20, 1e-3);
hold on
plot(xa, Fa(xa), "o");
hold off
title("F = 4 * cos(x) - e .^ (2 * x)");
subplot(3, 2, 2);
plot(y, Fb(y));
[i, xb] = bissecao(Fb, 2, 3, 20, 1e-3);
hold on
plot(xb, Fb(xb), "o");
hold off
title("F = (x / 2) -  tan(x)");
subplot(3, 2, 3);
plot(y, Fc(y));
[i, xc] = bissecao(Fc, 2, 3, 20, 1e-3);
hold on
plot(xc, Fc(xc), "o");
hold off
title("F = 1 - x * log(x)");
subplot(3, 2, 4);
plot(y, Fd(y));
[i, xd] = bissecao(Fd, 2, 3, 20, 1e-3);
hold on
plot(xd, Fd(xd), "o");
hold off
title("F = 2 .^ x - 3 * x");
subplot(3, 2, 5);
plot(y, Fe(y));
[i, xe] = bissecao(Fe, 2, 3, 20, 1e-3);
hold on
plot(xe, Fe(xe), "o");
hold off
title("F = x .^ 3 + x - 1000");
