% Processamento de Imagens - Avaliação 2
% Aluno: Ivo Henrique Provensi Vieira
% Matrícula: 201910633
% Questão 1

function h = dissolve_cruzado(f, g, t)
  pkg load image;

  [lin col] = size(f);
  th = zeros(size(f));

  for (i = 1 : lin)
    for (j = 1 : col)
      if (t == 'rc')
        th(i, j) = (i + j) / (lin + col - 2);
      elseif (t == 'c')
        th(i, j) = j / (col - 1);
      else
        th(i, j) = i / (lin - 1);
      endif
    endfor
  endfor

  for (i = 1 : lin)
    for (j = 1 : col)
      h(i, j) = ((1 - th(i, j)) * f(i, j)) + (th(i, j) * g(i, j));
    endfor
  endfor
endfunction
