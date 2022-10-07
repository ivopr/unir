clc;
clearvars;
A = [1 2 3
     4 5 6
     7 8 9];

% 1. Trocar todos os elementos da 3a coluna por 11.
thirdColumnChange = A;
thirdColumnChange(:, 3) = 11;

% 2. Adicionar uma 4a coluna com todos elementos iguais a 5.
fourthColumnAdd = A;
fourthColumnAdd(:, 4) = 5;

% 3. Retornar uma matriz B de dimensão 2x2 que é formada pela retirada da primeira linha e primeira coluna de A.
B = A(2 : 3, 2 : 3);

% 4. Anexar à matriz A (em linha) uma matriz C de dimensão 3x3 gerada aleatoriamente.
C = rand(3);
D = [A C];

% 5. Anexar à matriz A (em coluna) uma matriz C de dimensão 3x6 gerada com elementos unitários.
C = ones(3, 6);
D = [D; C];

% 6. Retornar para B o primeiro vetor coluna da A.
B = A(:, 1);