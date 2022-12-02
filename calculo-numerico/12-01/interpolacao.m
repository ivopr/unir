# x0 = -1   y0 =  3
# x1 =  2 e y1 =  6
# x2 =  4   y2 = -2

# Função
# a0 + a1 * x + a2 * x^2

# Sistema
# a0 + a1 * x0 + a2 * x0^2
# a0 + a1 * x1 + a2 * x1^2
# a0 + a1 * x2 + a2 * x2^2

# Resolvendo o sistema
# a0 + a1 * -1 + a2 * -1^2 = a0 + (-a1) + a2
# a0 + a1 * 2 + a2 * 2^2 = a0 + 2*a1 + 4*a2
# a0 + a1 * 4 + a2 * 4^2 = a0 + 4*a1 + 16*a2

# Montando o sistema em octave
A = [1 -1 1; 1 2 4; 1 4 16];
B = [3; 6; -2];

a = A\B

f = @(x) 6 + 2 * x - 1 * x^2

# x0 = -1   y0 =  4
# x1 =  0 e y1 =  1
# x2 =  2   y2 = -1

# Função
# a0 + a1 * x + a2 * x^2

# Sistema
# a0 + a1 * x0 + a2 * x0^2
# a0 + a1 * x1 + a2 * x1^2
# a0 + a1 * x2 + a2 * x2^2

# Resolvendo o sistema
# a0 + a1 * -1 + a2 * -1^2 = a0 + (-a1) + a2
# a0 + a1 * 0 + a2 * 0^2 = a0 + 2*a1 + 4*a2
# a0 + a1 * 2 + a2 * 2^2 = a0 + 4*a1 + 16*a2

# Montando o sistema em octave
A = [1 -1 1; 1 2 4; 1 4 16];
B = [3; 6; -2];

a = A\B

f = @(x) 6 + 2 * x - 1 * x^2