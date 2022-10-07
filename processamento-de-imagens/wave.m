function [x y] = wave(img)
  pkg image load;
  [lin col] = size(img);
  [X Y] = meshgrid(1:lin, 1:col);

  for i=1:lin
    for j=1:col
      x(i, j) = i + 20 * sin((2 * pi * j) / 128);
      y(i, j) = j;
    endfor
  endfor

  img_saida = interp2(X, Y, img, y, x, 'linear');
  figure, imshow(img_saida);
 endfunction

 # comandos
 # img = imagem;
 # [lin col] = size(img);
 # [X Y] = meshgrid(1:lin, 1:col); % coordenadas originais da imagem
 # [p q] = wave1(img);
 # img_saida = interp2(X, Y, img, q, p, 'linear');
 # imshow(img_saida);
