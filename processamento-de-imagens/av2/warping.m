% Processamento de Imagens - Avaliação 2
% Aluno: Ivo Henrique Provensi Vieira
% Matrícula: 201910633
% Questão 4

function g = warping(img, x0, y0)
  pkg load image;

  [lin col] = size(img);
  [X Y] = meshgrid(1 : lin, 1 : col);

  for (u = 1 : lin)
    for (v = 1 : col)
      r = ((u - x0) ^ 2 + (v - y0) ^ 2) ^ 0.5;
      theta = pi * r / lin;
      y(u, v) = -(u - x0) * sind(theta) + (v - y0) * cosd(theta) + y0;
      x(u, v) = (u - x0) * cosd(theta) + (v - y0) * sind(theta) + x0;
    endfor
  endfor
  g = interp2(X, Y, img, y, x, 'linear');
endfunction
