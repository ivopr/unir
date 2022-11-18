# Questão 4
%{
A precisão de máquina é definida como sendo o menor número positivo em
aritmética de ponto flutuante 𝛆, tal que (1+ 𝛆) > 1. Este número depende totalmente
do sistema de representação da máquina: base numérica, total de dígitos na
mantissa, da forma como são realizadas as operações e do compilador utilizado. É
importante conhecermos a precisão da máquina porque em vários algoritmos
precisamos fornecer como dado de entrada um valor positivo, próximo de zero,
para ser usado em teste de comparação com zero.
O algoritmo a seguir estima a precisão da máquina:
Passo 1: A = 1
s = 2;
Passo 2: Enquanto (s) > 1, faça:
A = A/2
s = 1 + A
Passo 3: Faça Prec = 2*A e imprima Prec.
a. Teste este algoritmo escrevendo um programa usando Octave (ou outra
linguagem). Declare as variáveis do programa em precisão simples
(single/float) e execute o programa; em seguida, declare as variáveis em
precisão dupla (double) e execute novamente.
b. Interprete o passo 3 do algoritmo, isto é, por que a aproximação para Prec é
escolhida como sendo o dobro do último valor de A obtido no passo 2?
c. Na definição de precisão de máquina, usamos como referência o número 1.
No algoritmo a seguir, a variável VAL é um dado de entrada, escolhido pelo
usuário:
Passo 1: A = 1
s = VAL + A;
Passo 2: Enquanto (s) > VAL, faça:
A = A/2
s = VAL + A
Passo 3: Faça Prec = 2*A e imprima Prec
i. Teste seu programa atribuindo para VAL os números: 10, 17, 100,
184, 1000, 1575, 10000, 17893.
ii. Para cada valor diferente para VAL, imprima o valor correspondente
obtido para Prec. Justifique por que Prec se altera quando VAL é
modificado.
%}

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
