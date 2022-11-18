function [A, t] = verificaTriangulacao(A)
  if(verificaTriangulacaoCima(A) != -1)
    t = 1; % cima
    return
  endif

  if(verificaTriangulacaoBaixo(A) != -1)
    t = 2; % baixo
    return
  endif

  A = triangulador(A);
  t = 2;
  return
endfunction
