# Questão 1
x = [1; 2; 3; 4; 5; 6; 7];
y = [0.5; 2.5; 2; 4; 3.5; 6; 5.5];

[n,~] = size(x);

a2 = (n * sum(x .* y) - sum(x) * sum(y)) / (n * sum(x .^ 2) - (sum(x).^2));
# a2 = 0.8393 

a1 = (sum(y) - sum(x .* a2)) / n;
# a1 = 0.071429

f = @(x) 0.071429 + 0.8393 * x;