/*
  estrutura de dados 1
  lista 1 - ex 1
  aluno: ivo vieira
  compilador: gcc 9.1.0 (linux), TDM-GCC 4.9.2 x64 (dev-cpp)
  sistema operacional: manjaro 18.0.4
*/

#include <ed.h>

int main() {
	double num, num1;

	// famoso while true pra repetir eternamente at� o usu�rio decidir parar...
	while(1) {
		limpar();
		printf("operacoes basicas: +, -, /, *.\npara sair pressione CTRL + D ou CTRL + Z (Windows)\n");

		// inser��o de dados
		printf("insira dois numeros: ");
		scanf("%lf %lf", &num, &num1);

			// verifica se o usu�rio pressionou as teclas de saida (EOF), caso seja verdade, encerra o loop
			if(feof(stdin)) {
				break;
			}
			
		// exibe os resultados da soma, subtra��o, multiplica��o e diviss�o entre os dois n�meros inseridos.
		printf("soma: %.2lf\n", num + num1);
		printf("subtracao: %.2lf\n", num - num1);
		printf("multiplicacao: %.2lf\n", num * num1);
		printf("divisao: %.2lf\n", num / num1);

		parar();
	}
}
