function v = d2b(a)
  n = 16;
  m = 25;
  v = fix(rem(a * pow2(-(n - 1) : m), 2));
endfunction