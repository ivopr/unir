function f = wave1(img)
  pkg image load;
  [lin col] = size(img);
  for i=1:lin
    for j=1:col
      x(i, j) = i + 20*sin((2*pi*i)/30);
      y(i, j) = j;
      imgr(x, y) = img(i, j);
    endfor
  endfor
  f = imgr;
 endfunction
