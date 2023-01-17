#x = [0 0.25 0.5 0.75 1]'
#y = [-153 64 242 284 175]'

#x = [0 1 2 3 4 5]'
#y = [2.1 7.7 13.6 27.2 40.9 61.1]'


function [a] = mmq_polinomial(x, y, k)
  n = length(x);
  for i=1:n
    for j=1:k+1
      V(i,j) = x(i)^(j-1);
    endfor
  endfor
  V
  a = (inv(V'*V))*V'*y;
endfunction