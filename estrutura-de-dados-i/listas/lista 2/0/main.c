/*
	estrutura de dados I
	lista 2 - ex 0
	aluno: ivo vieira
	compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 (dev-cpp)
	sistema operacional: manjaro 18.0.4
*/
#include <ed.h>

	int main()
	{
		double num;
		
		// while true
		while(1)
		{
			limpar();
			printf("raiz quadrada ou numero ao quadrado - pressione CTRL+D (linux) ou CTRL+Z (windows) para sair.\n");
			
			// entrada de dados
			printf("insira um numero: ");
			scanf("%lf", &num);
			
			// verifica eof, caso exista, encerra o programa
			if(feof(stdin))
				break;
			
			// exibe resultados
			if(num > 0)
				printf("a raiz quadrada de %.2lf eh: %.2lf\n", num, sqrt(num));
			else if(num < 0)
				printf("%.2lf ao quadrado eh: %.2lf\n", num, pow(num, 2));
			else
				printf("%.2lf eh neutro.\n", num);
			
			parar();
		}
	}
	
