/***************************************************************************************
* Alunos: Murilo Fuza da Cunha & Ivo Henrique Provensi Vieira
* Curso: Bacharelado (Licenciatura) em Ciências da Computação
*
* Lista 2: Grafos - Implementações
*
* Estrutura de Dados II - 2020 -- DACC/UNIR, - Profa.Carolina Watanabe
* Compilador: Microsoft (R) C/C++ Optimizing Compiler Versão 19.00.24245 (msvc 2019)
* Sistema Operacional: Windows 10 Pro
***************************************************************************************/

#include "gMtz.h"
#include "utils.h"

int main() {
	int op = 0, vrt, vrt1;
	gMtz* m = new gMtz();
	string nome;
	utils u;

	m->popularMtz();
	do {
		u.clrscr();
		cout << "1 - carregar outro grafo" << endl
			 << "2 - exibir" << endl
			 << "3 - busca em largura" << endl
		  	 << "4 - busca em profundidade" << endl
		 	 << "5 - arvore geradora minima (prim)" << endl
			 << "6 - arvore geradora minima (kruskal)" << endl
			 << "7 - caminho minimo (busca em largura)" << endl
			 << "8 - caminho minimo (dijkstra)" << endl
			 << "9 - caminho minimo (floyd)" << endl
			 << ">>> menu.: ";
		cin >> op;
		switch (op) {
		case 1:
			m->popularMtz();
			u.pause();
			break;

		case 2:
			m->exibirMtz();
			u.pause();
			break;

		case 3:
			cout << "qual o vertice inicial: ";
			cin >> vrt;
			m->bfs(vrt);
			u.pause();
			break;

		case 4:
			cout << "qual o vertice inicial: ";
			cin >> vrt;
			m->dfs(vrt);
			u.pause();
			break;

		case 5:
			m->primAGM();
			u.pause();
			break;

		case 6:
			m->kruskalAGM();
			u.pause();
			break;

		case 7:
			cout << "qual o vertice origem e destino: ";
			cin >> vrt >> vrt1;
			m->bfsCM(vrt, vrt1);
			u.pause();
			break;

		case 8:
			cout << "qual o vertice origem: ";
			cin >> vrt;
			m->dijkstraCM(vrt);
			u.pause();
			break;

		case 9:
			m->FloydWCM();
			u.pause();
			break;
		}
	} while (op != 0);
	m->encerraMtz();
	exit(EXIT_SUCCESS);
}
