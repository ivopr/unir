function newimg = rotation(img, ang, x, y)
  pkg image load;
  [lin col] = size(img);

  for i=1:lin
    for j=1:col
      newI = uint8((i - x) * cosd(ang) - (j - y) * sind(ang) + x) + 1;
      newJ = uint8((i - x) * sind(ang) + (j - y) * cosd(ang) + y) + 1;
      imgr(newI, newJ) = img(i, j);
    endfor
  endfor
  newimg = imgr;
 endfunction
