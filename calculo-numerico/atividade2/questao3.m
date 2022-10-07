# Questão 3

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
