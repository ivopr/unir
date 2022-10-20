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
