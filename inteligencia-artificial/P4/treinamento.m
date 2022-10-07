function [net] = treinamento
    clc;
    clearvars;
    M = load('treinamento.txt');
    vet_entrada = M(:,1:3)';
    vet_desejado = M(:,4)';

    vmin = min(vet_entrada');
    vmax = max(vet_entrada');

    net = newff([vmin' vmax'], [20 20 1], {'tansig', 'tansig', 'purelin'}, 'trainbr');

    net.trainParam.epochs = 200;
    net.trainParam.goal = 1e-4;
    net.trainParam.lr = 0.01;
    net.trainParam.show = 5;

    net = train(net, vet_entrada, vet_desejado);
    
    vet_saida = sim(net, vet_entrada);
    
    erro_relativo = abs(vet_saida - vet_desejado) ./ abs(vet_desejado);
    disp("erm treino ");
    mean(erro_relativo)
end