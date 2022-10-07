clc;
clearvars;

M = load('treinamento.txt');

%Vetor T de entradas
[mLin, mCol] = size(M);
T = [-ones(mLin, 1) M(:,1:5)];

%Vetor D de resultados desejados
d = M(:,6);

%Taxa de aprendizagem
n = 0.0025;

%Contador de épocas
e = 0;

%Parâmetro de precisão
p = 1e-6;

%Vetor de pesos aleatóriamente iniciado e com a coluna de -1
w = rand(mCol,1);

eqm_ant = 0;
eqm_atual = EQM(T, w, d);

while abs(eqm_atual - eqm_ant) >= p
	e = e + 1;
	eqm_ant = eqm_atual;
	for k = 1 : mLin
		x = T(k,:)';
		u = w' * x;
		w = w + n * (d(k) - u) * x;
	end
	eqm_atual = EQM(T, w, d);
	erro(e) = eqm_atual;
end

[l, c] = size(erro);

figure,
plot(erro, 'g')
xlim([0 c])