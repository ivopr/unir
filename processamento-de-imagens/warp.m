function [p q] = warp(img, x0)
  [lin col] = size(img);
  [X Y] = meshgrid(1:lin, 1:col);
  for (u = 1 : lin)
    for (v = 1 : col)
      y(u, v) = v;
      x(u, v) = sign(u - x0) * (u - x0)^2 / x0 + x0;
    endfor
  endfor
  img_saida = interp2(X, Y, img, y, x, 'linear');
  figure, imshow(img_saida);
endfunction
