x = [1.6; 5.17; 6; 13];
y = [2.9; 5.37; 8; 2];

V = [x.^2 x x.^0];
a = V\y;

f = @(x) -0.1443 + 2.0454 * x + -0.1575 * x.^2;

yApprox = f(x);
# yApprox =
#    2.7251
#    6.2206
#    6.4581
#   -0.1716

Sr = sum((y - yApprox) .^ 2);
# Sr = 7.8474