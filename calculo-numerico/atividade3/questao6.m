%{
Escreva um programa em Octave para solucionar um sistema linear. O
programa deve receber como entrada uma matriz quadrada de ordem nxm e
um vetor coluna b nx1 e retornar como saída o vetor solução x. O programa
também deve verificar os seguintes casos:
- 1º) O programa deve verificar se a matriz informada é quadrada. Se não for,
o programa deve ser encerrado.
- 2º) Se a matriz fornecida é triangular superior ou inferior; Nesse caso,
conforme a identificação do tipo, o programa deve usar o método adequado
para solucionar o sistema;
- 3º) Se a matriz fornecida não for triangular, o programa deve triangularizar e
solucionar o problema utilizando o método adequado.
%}

function [x] = questao6(A, b)
  [l, c] = size(A);

  if(l != c)
    return
  endif

  [A, t] = verificaTriangulacao(A);
  [n, ~] = size(A);

  if(t == 2)
    x = substituicaoDireta(A, b, n);
    return
  endif

  if(t == 1)
    x = substituicaoReversa(A, b, n);
    return
  endif
endfunction
