# Questao 4

# A
A = [
  12  0 0  12;
   3 -7 0 -11;
  -4  2 6  18;
];
b = [12, -11, 18];
n = 3;

[x] = substituicaoDireta(A,b,n)

# B
B = [
  2 0 0 0  8;
  0 5 0 0 15;
  9 6 7 0 68;
  0 4 6 9 33;
];

b = [8, 15, 68, 33];
n = 4;

[x] = substituicaoDireta(B,b,n)
