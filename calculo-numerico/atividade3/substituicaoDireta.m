function x = substituicaoDireta(a, b, n)
  x = zeros(1, n);
  for k = 1 : n
    somatorio = 0;
    for j =  1 : k - 1
      somatorio += a(k, j) * x(j);
    endfor

    x(k) = (b(k) - somatorio) / a(k, k);
  endfor
endfunction
