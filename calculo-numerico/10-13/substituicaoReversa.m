function x = substituicaoReversa(a, b, n)
  x = zeros(1, n);
  for k = 1 : n
    i = n - k + 1;

    somatorio = 0;
    for j =  i + 1 : n
      somatorio += a(i, j) * x(j);
    endfor

    x(i) = (b(i) - somatorio) / a(i, i);
  endfor
endfunction
