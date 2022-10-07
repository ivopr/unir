% G = MOVINGTHRESH ( F , n , K ) segmenta a imagem F limitando suas
% intensidades com base na média móvel das intensidades ao longo
% das linhas individuais da imagem. A média em pixel k é formada
% pela média das intensidade desse pixel e seus n-1 vizinhos anteriores.
% Para reduzir o viés de sombreamento, o scanning é feito em zig-zag
% tratando os pixels como se fossem um 1-D, fluxo contínuo. Se o valor da imagem
% em um ponto excede k por cento do valor da média corrente naquele ponto,
% um 1 é emitido nesse local em G. Caso contrário, um 0 é emitido.
% No final do procedimento, G é, portanto, a imagem limiarizada.
% K deve ser um escalar no intervalo [0, 1]
function g = movingthresh(f, n, k)
  pkg load image;
  f = im2double(f);
  [M, N] = size(f);
  if (n < 1) || (rem(n, 1) ~= 0)
    error('n deve ser um numero inteiro >= 1');
  endif
  if k < 0 || k > 1
      error('k deve ser um numero fracionário entre 0 e 1');
  endif
  f(2:2:end, :) = fliplr(f(2:2:end, :));
  f = f';
  f = f(:)';

  maf = ones(1, n)/n;
  ma = filter(maf, 1, f);

  g = f > k * ma;
  g = reshape(g, N, M)';
  g(2:2:end, :) = fliplr(g(2:2:end, :));
endfunction

