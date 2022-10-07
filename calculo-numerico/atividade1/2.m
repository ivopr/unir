A = zeros(15);
[lin, col] = size(A);

for i = 1 : lin
  for j = 1 : col
    if(i == j)
      A(i, j) = 2;
    elseif((j > i) && (j - i) == 1)
      A(i,j) = 3;
    endif
  endfor
endfor