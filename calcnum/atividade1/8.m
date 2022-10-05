# a. Octal -> Decimal
function v = t(a)
  v = [];
  o = num2str(a); 
  d = 0;
  f = fliplr(o);
  for p = 0 : length(o) - 1;
    d = d + str2num(f(p + 1)) * 8^p;
  endfor
endfunction

# b. decimal -> binario
function v = d2b(a)
  # dec 2 bin
  n = 16;
  m = 25;
  v = fix(rem(a * pow2(-(n - 1) : m), 2));
endfunction

# c. binario -> decimal
function v = b2d(a)
  # bin 2 dec
  n = 16;
  m = 25;
  v = a * pow2(n - 1 : -1 : -m).';
endfunction