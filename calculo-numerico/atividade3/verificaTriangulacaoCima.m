function [t] = verificaTriangulacaoCima(A)
  [n, ~] = size(A);

  for i = 1:n
    for j = i:n
      if(i != j && j > i)
        if(A(i,j) != 0)
          t = -1;
          return
        endif
      endif
    endfor
  endfor
  t = 1;
endfunction
