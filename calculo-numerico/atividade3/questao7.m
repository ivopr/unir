# Questao 7
%{
Resolva os sistemas lineares a seguir utilizando o Método de Gauss com
Pivotamento Parcial. Substitua as soluções encontradas nos sistemas
originais para verificar se os seus resultados estão corretos.
%}
printf("Letra A:\n");
aA = [
   4  5 -6;
   2  0 -7;
  -5 -5  0;
];

aB = [28; 29; -65];

[aAt, aBt] = eliminacaoGaussiana(aA, aB);

aSol = aAt\aBt;

aBSol = [aA(1,:) * aSol; aA(2,:) * aSol; aA(3,:) * aSol];

[aA aBSol]


printf("\n\nLetra B:\n");
bA = [
  0  3 -13;
  2 -6   1;
  4  0   8;
];

bB = [-50; 45; 4];

[bAt, bBt] = eliminacaoGaussiana(bA, bB);

bSol = bAt\bBt;

bBSol = [bA(1,:) * bSol; bA(2,:) * bSol; bA(3,:) * bSol];

[bA bBSol]


printf("\n\nLetra C:\n");
cA = [
  10 -3  6;
   1  8 -2;
  -2  4 -9;
];

cB = [24.5; -10; -50];

[cAt, cBt] = eliminacaoGaussiana(cA, cB);

cSol = cAt\cBt;

cBSol = [cA(1,:) * cSol; cA(2,:) * cSol; cA(3,:) * cSol];

[cA cBSol]

