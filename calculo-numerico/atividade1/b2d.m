function v = b2d(a)
  # bin 2 dec
  n = 16;
  m = 25;
  v = a * pow2(n - 1 : -1 : -m).';
endfunction
