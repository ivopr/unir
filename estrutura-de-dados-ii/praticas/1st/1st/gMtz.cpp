#include "gMtz.h"

bool gMtz::arestaExiste (int v, int v1) {
	// retorna verdadeiro se a posição v,v1 já estiver ocupada, ou seja, a aresta existe
	// por lógica, a aresta v1,v também existe, já que é uma matriz sem peso.
	return this->mtz[v][v1] != INT_MAX;
}

bool gMtz::arestaValida(int v, int v1, vector<bool> arvore) {
	if(v == v1) return false;
	if(arvore[v] == false && arvore[v1] == false) return false;
	if(arvore[v] == true && arvore[v1] == true) return false;
	return true;
}

bool gMtz::encerraMtz() {
	if(this->verificaMtzVazia()) return false;
	for(int i = 0; i < this->ttlVrt; i++)
		free(this->mtz[i]);
	free(this);
	return true;
}

bool gMtz::inserirAresta (int v, int v1, int peso) {
	// verifica se os vértices tem valor maior que o numero total de vértices ou se são menores que 0
	if(v > this->ttlVrt || v1 > this->ttlVrt || v < 0 || v1 < 0) return false;

	// verifica se as arestas v,v1 e v1,v já existem, se sim, retorna falso
	if(arestaExiste (v, v1)) return false;

	// cria as arestas v,v1 e v1,v
	if (this->tpGrf == 0) {
		this->mtz[v][v1] = peso;
		this->mtz[v1][v] = peso;

		this->mtzAux[v][v1] = peso;
		this->mtzAux[v1][v] = peso;
	} else if (this->tpGrf == 1) {
		this->mtz[v][v1] = peso;

		this->mtzAux[v][v1] = peso;
	}

	// chegou aqui, então está tudo bem, retorna verdadeiro
	return true;
}

bool gMtz::popularMtz() {
	int destino, origem, peso;
	string linha, nome;

	cout << "insira o nome do arquivo .txt (sem extensao): ";
	cin >> nome;

	// abre o arquivo
	ifstream arquivo(nome.append(".txt"));

	// se o arquivo não tiver aberto com sucesso, retorna falso
	if(!arquivo.is_open()) return false;

	// põe a primeira linha do arquivo na variável linha
	getline(arquivo, linha);
	
	// passa a linha para uma variável utilizavel
	istringstream iss(linha);

	// o conteúdo da primeira linha sempre é apenas um número, então passamos ele para a variavel ttlVrt
	// da classe
	iss >> this->ttlVrt >> this->tpGrf;

	// verifica se foi possível criar um grafo vazio, se não for possível, retorna falso
	this->iniciaMtz(this->ttlVrt);

	// sempre pega a próxima linha do arquivo e põe na variavel linha
	while(getline(arquivo, linha)) {
		// pega essa nova linha e põe numa variável utilizável helper
		istringstream helper(linha);

		// na linha, sempre vai ter ao menos 2 itens, a ORIGEM e o DESTINO, ou, v e v1, então passamos eles
		// para as variáveis origem e destino
		helper >> origem >> destino >> peso;

		// verific se a aresta já existe, se existir, ignora, se não, insere
		if(!this->arestaExiste(origem, destino))
			this->inserirAresta(origem, destino, peso);
	}
	// fecha arquivo
	arquivo.close();

	// se chegou até aqui, não deu merda nenhuma, então retorna verdadeiro
	return true;
}

bool gMtz::verificaMtzVazia() {
	if(this->ttlVrt == 0) return true;
	return false;
}

gMtz::gMtz() {
	this->mtz = NULL;
	this->mtzAux = NULL;
	this->ttlVrt = this->tpGrf = 0;
}

void gMtz::exibirMtz() {
	if(this->verificaMtzVazia()) cout << "nao eh possivel exibir uma matriz vazia" << endl;
	for(int i = -1; i < this->ttlVrt; i++) {
		if(i == -1) {
			cout << "   ";
			for(int k = 0; k < this->ttlVrt; k++) {
				cout << k << " ";
			}
			cout << endl;
		}
		if(i != -1) {
			cout << i << "  ";
			for(int j = 0; j < this->ttlVrt; j++) {
				if(this->mtz[i][j] == INT_MAX)
					cout << "0 ";
				else
					cout << this->mtz[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void gMtz::exibirMtzAux() {
	if (this->verificaMtzVazia()) cout << "nao eh possivel exibir uma matriz vazia" << endl;
	for (int i = -1; i < this->ttlVrt; i++) {
		if (i == -1) {
			cout << "   ";
			for (int k = 0; k < this->ttlVrt; k++) {
				cout << k << " ";
			}
			cout << endl;
		}
		if (i != -1) {
			cout << i << "  ";
			for (int j = 0; j < this->ttlVrt; j++) {
				if (this->mtzAux[i][j] == INT_MAX)
					cout << "0 ";
				else
					cout << this->mtzAux[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void gMtz::exibirDist(vector<int>& dist) {
	cout << "Vertice \t\t Distancia em relacao ao inicio" << endl;
	for (int i = 0; i < this->ttlVrt; i++)
		if(dist[i] != INT_MAX)
			cout << i << " \t\t " << dist[i] << endl;
}

void gMtz::bfs(int inicio) {
	vector<bool> visitado(this->ttlVrt, false);
	vector<int> fila;
	fila.push_back(inicio);

	visitado[inicio] = true;

	int v;
	while(!fila.empty()) {
		v = fila[0];

		cout << v << " ";
		fila.erase(fila.begin());

		for(int i = 0; i < this->ttlVrt; i++) {
			if(this->mtz[v][i] != INT_MAX && (!visitado[i])) {
				fila.push_back(i);
				visitado[i] = true;
			}
		}
	}
	cout << endl;
}

void gMtz::dfs(int inicio) {
	vector<bool> visitado(this->ttlVrt, false);
	this->dfsAux(inicio, visitado);
	cout << endl;
}

void gMtz::dfsAux(int inicio, vector<bool>& visitado) {
	cout << inicio << " ";
	visitado[inicio] = true;
	for(int i = 0; i < this->ttlVrt; i++) {
		if(this->mtz[inicio][i] != INT_MAX && (!visitado[i])) {
			this->dfsAux(i, visitado);
		}
	}
}

void gMtz::bfsCM(int o, int d) {
	vector<bool> vis(this->ttlVrt, false);
	vector<int> ant(this->ttlVrt);
	vector<int> dist(this->ttlVrt, 0);
	vector<int> adj(this->ttlVrt, 0);

	list<int> fila;

	dist[o] = 0;
	vis[o] = true;

	fila.push_back(o);

	while (!fila.empty()) {
		int u = fila.front();
		fila.pop_front();

		this->adjacentes(adj, u);

		for (int i = 0; i < this->ttlVrt; i++) {
			if (adj[i] == 1) {
				if (vis[i] == false) {
					vis[i] = true;
					dist[i] = dist[u] + this->mtz[u][i];
					fila.push_back(i);
				}
			}
		}
	}
	if (dist[d] != -1) {
		cout << "Distancia: " << o << " -> " << d << ": " << dist[d] << endl;
	}
}

void gMtz::adjacentes(vector<int>& lista, int v) {
	for (int i = 0; i < this->ttlVrt; i++) {
		if (this->mtz[v][i] != INT_MAX) {
			lista[i] = 1;
		}
	}
}

int gMtz::minDist(vector<int>& dist, vector<bool>& spt) {
	int min = INT_MAX, min_index = 0;
	for(int i = 0; i < this->ttlVrt; i++)
		if(spt[i] == false && dist[i] <= min)
			min = dist[i], min_index = i;
	return min_index;
}

void gMtz::exibeCaminho(vector<int>& cam, int j) {
	if(cam[j] == -1)
		return;
	this->exibeCaminho(cam, cam[j]);
	cout << j << " ";
}

void gMtz::exibeDijkstra(vector<int>& dist, vector<int>& cam) {
	int src = 0;
	cout << "Vertice\t Distancia\t Caminho";
	for (int i = 1; i < this->ttlVrt; i++) {
		if(dist[i] != INT_MAX) {
			cout << endl << src << " -> " << i << " \t\t " << dist[i] << "\t\t" << src << " ";
			this->exibeCaminho(cam, i);
		}
	}
	cout << endl;
}

void gMtz::exibirMtz(int** matriz) {
	if (this->verificaMtzVazia()) cout << "nao eh possivel exibir uma matriz vazia" << endl;
	for (int i = -1; i < this->ttlVrt; i++) {
		if (i == -1) {
			cout << "   ";
			for (int k = 0; k < this->ttlVrt; k++) {
				cout << k << " ";
			}
			cout << endl;
		}
		if (i != -1) {
			cout << i << "  ";
			for (int j = 0; j < this->ttlVrt; j++) {
				if (matriz[i][j] == INT_MAX)
					cout << "0 ";
				else
					cout << matriz[i][j] << " ";
			}
			cout << endl;
		}
	}
}

void gMtz::FloydWCM() {
	for(int i = 0; i < this->ttlVrt; i++) {
		for(int j = 0; j < this->ttlVrt; j++) {
			if(this->mtzAux[i][j] != INT_MAX - 10) {
				for(int k = 0; k < this->ttlVrt; k++) {
					this->mtzAux[i][k] = min(this->mtzAux[i][k], this->mtzAux[i][j] + this->mtzAux[j][k]);
				}
			}
		}
	}
	this->exibirMtzAux();
}

void gMtz::dijkstraCM(int origem) {
	vector<int> dist(this->ttlVrt, INT_MAX);
	vector<bool> spt(this->ttlVrt, false);
	vector<int> sptStore(this->ttlVrt, NULL);

	for (int i = 0; i < this->ttlVrt; i++) {
		dist[i] = INT_MAX;
		spt[i] = false;
		sptStore[0] = -1;
	}

	dist[origem] = 0;

	for(int cont = 0; cont < this->ttlVrt - 1; cont++) {
		int u = this->minDist(dist, spt);
		spt[u] = true;
		for (int v = 0; v < this->ttlVrt; v++) {
			if (spt[v] == false && this->mtz[u][v] != INT_MAX && dist[u] != INT_MAX && dist[u] + this->mtz[u][v] < dist[v]) {
				sptStore[v] = u;
				dist[v] = dist[u] + this->mtz[u][v];
			}
		}
	}
	this->exibeDijkstra(dist, sptStore);
}

void gMtz::iniciaMtz(int nvt) {
	this->ttlVrt = nvt;
	this->mtz = new int* [this->ttlVrt];
	this->mtzAux = new int* [this->ttlVrt];
	for(int lin = 0; lin < this->ttlVrt; lin++) {
		this->mtz[lin] = new int[this->ttlVrt];
		this->mtzAux[lin] = new int[this->ttlVrt];
		for(int col = 0; col < this->ttlVrt; col++) {
			this->mtz[lin][col] = INT_MAX;
			this->mtzAux[lin][col] = INT_MAX - 10;
		}
	}
}

int gMtz::encontraSet(vector<int>& arvore, int i) {
	while(arvore[i] != i)
		i = arvore[i];
	return i;
}

void gMtz::kruskalAGM() {
	int custoM = 0;
	vector<int> arvore(this->ttlVrt);

	for(int i = 0; i < this->ttlVrt; i++) {
		arvore[i] = i;
	}

	int arestas = 0;
	while(arestas < this->ttlVrt - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for(int i = 0; i < this->ttlVrt; i++) {
			for(int j = 0; j < this->ttlVrt; j++) {
				if(this->encontraSet(arvore, i) != this->encontraSet(arvore, j) && this->mtz[i][j] < min) {
					min = this->mtz[i][j];
					a = i;
					b = j;
				}
			}
		}
		this->uniao(arvore, a, b);
		cout << "aresta " << arestas++ << ": (" << a << ", " << b << ") custo: " << min << endl;
		custoM += min;
	}
	cout << "custo minimo: " << custoM << endl;
}

void gMtz::uniao(vector<int>& arvore, int i, int j) {
	int a = this->encontraSet(arvore, i);
	int b = this->encontraSet(arvore, j);
	arvore[a] = b;
}

void gMtz::primAGM() {
	vector<bool> arvore(this->ttlVrt, false);
	arvore[0] = true;

	int arestas = 0, custoM = 0;
	while(arestas < this->ttlVrt - 1) {
		int min = INT_MAX, a = -1, b = -1;
		for(int i = 0; i < this->ttlVrt; i++) {
			for(int j = 0; j < this->ttlVrt; j++) {
				if(this->mtz[i][j] < min) {
					if(this->arestaValida(i, j, arvore)) {
						min = this->mtz[i][j];
						a = i;
						b = j;
					}
				}
			}
		}
		if(a != -1 && b != -1) {
			cout << "aresta " << arestas++ << ": (" << a << ", " << b << ") custo: " << min << endl;
			custoM += min;
			arvore[a] = arvore[b] = true;
		}
	}
	cout << "custo minimo: " << custoM << endl;
}
