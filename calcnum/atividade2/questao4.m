# Questão 4

printf("Letra A)\n");
printf("Single Precision\n");
A = single(1);
S = single(2);

while S > 1
	A = single(A / 2);
	S = single(1 + A);
endwhile
Prec = single(2 * A)

printf("Double Precision\n");
A = 1;
S = 2;

while S > 1
	A = A / 2;
	S = 1 + A;
endwhile
Prec = 2 * A

printf("\nLetra B) Pois uma divisão tem maiores chances de gerar um número com casas decimais\n\n");

# Questão 4 - C
printf("Letra C)\n");
VAL = input("Defina VAL: ");
A = 1;
S = VAL + 1;

while S > VAL
	A = A / 2;
	S = VAL + A;
endwhile
Prec = 2 * A

# Questão 4 - C ii
printf("\nLetra C/ii) O valor de Prec se altera ao trocar o valor de VAL pois quanto maior o VAL, mais iterações são realizadas logo, menor o valor final de A\n");
