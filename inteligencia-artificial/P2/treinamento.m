%Aula Prática Perceptron - Aprendizagem Hebb
function [w] = treinamento
    clc;
    clearvars;

    %Carregando o arquivo de treinamento
    file = load('t.txt');

    %Copiando os valores dos x1, x2 e x3.
    xValues = file(:,1:3);

    %Tamanho da matriz
    [xLines, xCols] = size(xValues);

    %Adicionando a coluna de -1
    xValues = [-ones(xLines, 1) xValues];

    %Copiando os valores dos resultados desejados.
    desiredOutput = file(:,4);

    %Iniciando os pesos e limiar de ativação
    w = rand(4,1);

    %Taxa de Aprendizagem
    n = 0.01;

    %Inicia o contador de épocas
    runs = 0;

    %Iniciando o erro
    error = 1; %Inicialmente, existe

    while error 
        error = 0;
        runs = runs + 1;

        for k = 1 : xLines
            x = xValues(k,:)';
            u = w' * x;

            if (u >= 0)
                y = 1;
            else
                y = -1;
            end

            if (y ~= desiredOutput(k))
                w = w + n * (desiredOutput(k) - y) * x;
                error = 1;
            end
        end
    end
end
