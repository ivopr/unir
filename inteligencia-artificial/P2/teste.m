%Recebe como parametro o vetor W, e retorna a Classe. O vetor W é o vetor
%feito no treinamento
clc;
clearvars;

v = load('test.txt');
[vLines, vCols] = size(v);
v = [-ones(vLines, 1) v];

w = treinamento;
fid = fopen('res.txt', 'w');
for k = 1 : vLines
    x = v(k,:)';
    u = w' * x;
    if (u >= 0)
        y = 1;
        disp('normal');
    else
        y = -1;
        disp('iminencia de falha');
    end
    fprintf(fid, "%d\n", y);
end
fclose(fid);