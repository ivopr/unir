x = [1; 1.5; 2];
y = [1.2; 1.3; 2.3];

[n,~] = size(x);

somaxy = sum(x .* y) 
somax = sum(x) 
somay = sum(y)
somax2 = sum(x .^ 2)
somax22 = (sum(x).^2)

a2 = (n * sum(x .* y) - sum(x) * sum(y)) / (n * sum(x .^ 2) - (sum(x).^2))
# a2 = 0.8393 

somaya2 = sum(x .* a2)

a1 = (sum(y) - sum(x .* a2)) / n
# a1 = 0.071429

f = @(x) 0.071429 + 0.8393 * x;