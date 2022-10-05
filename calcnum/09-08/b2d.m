function v = b2d(a)
  n = 16;
  m = 25;
  v = a * pow2(n - 1 : -1 : -m).';
endfunction