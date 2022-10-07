function M = p6
    clc;
    clearvars;
    
    t = linspace(800, 1200, 40);

    p = linspace(4, 12, 80);

    varfis = readfis('p6');

    for i=1:40
        for j=1:80
            M(i,j) = evalfis([t(i) p(j)], varfis);
        end
    end
end