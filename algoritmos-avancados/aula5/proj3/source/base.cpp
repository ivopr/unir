#include<cstdio>
#include<iostream>
#include<cstring>
#define MAX 5

using namespace std;

int posicoes[8][2] = {
	{-1, -2},
	{-2, -1},
	{-2, 1},
	{-1, 2},
	{1, 2},
	{2, 1},
	{2, -1},
	{1, -2},

};

bool valido(int tab[MAX][MAX], int x, int y){
	if (x < 0 || x>= MAX || y < 0 || y>= MAX){
		return false;
	}
	if (tab[x][y] == 1){
		return false;		
	}
	return true;
}

void passeio(int tab[MAX][MAX], int x, int y, int cont){
	int nx, ny;
	if (cont == MAX*MAX){
		printf("Opa! Encontrei um passeio...\n");
	}else{
		for (int i=0; i< 8; i++){
			nx = x + posicoes[i][0]; // encontra nova posição
			ny = y + posicoes[i][1];
			if(valido(tab, nx, ny)){ // verifica se atende a restrição
				tab[nx][ny] = 1; // marca como visitado
				passeio(tab, nx, ny, cont+1); // verifica recursivamente
				tab[nx][ny] = 0; // desmarca como visitado para tentar novas possibilidades!
			}
		}
	}
	
}

int main(){
	
	int tab[MAX][MAX];
	int x = MAX/2;
	int y = MAX/2;
	memset(tab, 0, sizeof (tab)); // inicializa o tabuleiro com zeros;	
	//Onde o cavalo irá iniciar?
	tab[x][y] = 1; //visitado
	
	passeio(tab, x, y, 1);
	
	
	return 0;
}
