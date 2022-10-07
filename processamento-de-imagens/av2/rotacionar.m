% Processamento de Imagens - Avaliação 2
% Aluno: Ivo Henrique Provensi Vieira
% Matrícula: 201910633
% Questão 3

function g = rotacionar(f, x, y, theta)
  pkg load image;
  [lin col] = size(f);

  for (i = 1 : lin)
    for (j = 1 : col)
      newI = uint8((i - x) * cosd(theta) - (j - y) * sind(theta) + x) + 1;
      newJ = uint8((i - x) * sind(theta) + (j - y) * cosd(theta) + y) + 1;
      imgr(newI, newJ) = f(i, j);
    endfor
  endfor
  g = imgr;
 endfunction
