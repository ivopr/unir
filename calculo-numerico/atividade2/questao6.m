# Questão 6
%{
Escreva uma função em Octave para isolamento das raízes. A função deve
receber o intervalo [a, b] e o passo da iteração p. Utilize o Teorema de
Cauchy-Bolzano (f(a)*f(b) < 0) para determinar quantas raízes há entre o intervalo
definido. A função deve exibir uma mensagem informando o total de raízes
existentes no intervalo e, caso não exista, esse fato também deve ser informado.
%}
function cont = questao6(a, b, N)
	func = @(x) x .^ 3 - 9 * x + 3;

	cont = 0;
	while(a <= b)
		if((func(a) * func(b)) < 0)
			cont += 1;
		endif
		a += N;
	endwhile
endfunction
