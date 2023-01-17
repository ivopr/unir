function gera_grafico(f,x,y)
  hold all
  for i=1:length(x);
      plot(x(i), y(i), 'r*', 'linewidth', 4)
  endfor
  axis([-2*min(x(:)) 2*max(x(:))]);
  xx = linspace(-2*min(x(:)), 2*max(x(:)));
  plot(xx, f(xx))
  hold off
endfunction

#f = @(x) a(1) + a(2)*x + a(3)*x.^2

#f = @(x) a(1) + a(2)*x + a(3)*x.^2 + + a(4)*x.^3 + + a(5)*x.^4