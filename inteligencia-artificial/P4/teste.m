clc;
clearvars;
M = load('teste.txt');
vet_teste_entrada = M(:,1:3)';
vet_teste_desejado = M(:,4)';

net = treinamento;

vet_saida = sim(net, vet_teste_entrada);

erro_relativo = abs(vet_saida - vet_teste_desejado) ./ abs(vet_teste_desejado);

[vet_saida' vet_teste_desejado' erro_relativo']

disp("erm teste ");
mean(erro_relativo)