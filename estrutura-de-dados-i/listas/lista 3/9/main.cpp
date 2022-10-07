/*
	estrutura de dados I
	lista 3 - ex 9
	aluno: ivo vieira
	compilador: TDM-GCC
	sistema operacional: windows
*/
#include <iostream>
#include <string>
#include <azrael.h>
using namespace std;

class Cript
{
	public:
		string palavra;
		void criptografar();
		void descriptografar();
};

void Cript::criptografar()
{
	limpar();
	cout << "palavra a ser criptografada: ";
	cin >> palavra;

	for(unsigned int i = 0; i < palavra.length(); i++) {
		palavra[i] += 7;
	}
	cout << "palavra criptografada: " << palavra << endl;
		parar();
}

void Cript::descriptografar() {
	limpar();
	cout << "palavra criptografada: ";
	cin >> palavra;

	for(unsigned int i = 0; i < palavra.length(); i++) {
		palavra[i] -= 7;
	}
	cout << "palavra descriptografada: " << palavra << endl;
	parar();
}

int main()
{
  	int menu;
  	Cript c = Cript();

  	do
		{
			limpar();
			cout << "1 - criptografar" << endl << "2 - descriptografar" << endl << "0 - sair" << endl;
			cout << "menu> ";
			cin >> menu;

			switch(menu) {
				case 0: {
					break;
				}
				case 1: {
					c.criptografar();
					break;
				}
				case 2: {
					c.descriptografar();
					break;
				}
				default: {
					cout << "essa opcao nao existe no menu..." << endl;
					parar();
					break;
				}
			}
  } while(menu != 0);
  return 0;
}
