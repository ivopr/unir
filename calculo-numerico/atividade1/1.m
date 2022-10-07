A = [1 2; 3 4];
B = [1 1; 2 2];

# Matriz quadrada de zeros
C = (A + B) - (A + B)

# [4 3; 5 3]
D = (A * B) - (A .* B)

# [1 2; 9 16]
E = A .^ B
