# Questão 3
# Escreva um programa em Octave para obter o resultado da seguinte operação:
# 𝑆 = 10000 −
# 𝑘 = 1
# 𝑛
# ∑ 𝑥
# para: a) n = 100000 e x = 0,1; b) n = 80000 e x = 0,125;
## Letra A
x = 0.1;
xNext = x;
n = 100000;

for k = 1 : n
	xNext += x;
endfor
printf("Letra A - S = %f\n", 10000 - xNext);

## Letra B
x = 0.125;
xNext = x;
n = 80000;

for k = 1 : n
	xNext += x;
endfor
printf("Letra B - S = %f\n", 10000 - xNext);
