# Converta os seguintes números decimais para sua forma binária:

a = 37;
b = 2345;
c = 0.1217;

n = 16;
m = 25;
D2B = @(a) fix(rem(a * pow2(-(n - 1) : m), 2));

resa = mat2str(D2B(a))
resb = mat2str(D2B(b))
resc = mat2str(D2B(c))
