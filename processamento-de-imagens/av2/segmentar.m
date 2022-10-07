% Processamento de Imagens - Avaliação 2
% Aluno: Ivo Henrique Provensi Vieira
% Matrícula: 201910633
% Questão 5

function g = segmentar(f, met)
  pkg load image;

  switch(met)
    case 'otsu'
      h = imhist(f, 256);
      p = h / sum(h);
      omega = cumsum(p);
      mu = cumsum(p .* [1 : 256]');

      muT = mu(end);

      sigmaB = (muT .* omega - mu) .^ 2 ./ (omega .* (1 - omega));
      m = max(sigmaB);
      T = mean(find(sigmaB == m));
      g = f;

      g(g > T) = 255;
      g(g <= T) = 0;
    case 'global'
      count = 0;
      T = mean2(f);
      done = false;

      while(~done)
        count = count + 1;
        g = f > T;
        Tnext = 0.5 * (mean(f(g)) + mean(f(~g)));
        done = abs(T - Tnext) < 0.5;
        T = Tnext;
      endwhile
      g = f;

      g(g > T) = 255;
      g(g <= T) = 0;
    case 'mov'
      n = input("Insira o valor de n: ");
      k = input("Insira o valor de k: ");
      f = im2double(f);
      [M, N] = size(f);
      if (n < 1) || (rem(n, 1) ~= 0)
        error('n deve ser um numero inteiro >= 1');
      endif
      if k < 0 || k > 1
          error('k deve ser um numero fracionário entre 0 e 1');
      endif
      f(2 : 2 : end, :) = fliplr(f(2 : 2 : end, :));
      f = f';
      f = f(:)';

      maf = ones(1, n) / n;
      ma = filter(maf, 1, f);

      g = f > k * ma;
      g = reshape(g, N, M)';
      g(2 : 2 : end, :) = fliplr(g(2 : 2 : end, :));
  endswitch
endfunction
