A = [
  1 1 3 2 1;
  3 2 2 3 3;
  4 5 3 4 6;
  3 4 4 5 6;
  5 5 6 5 4;
];

B = [
  1 0 1 0 0 0;
  1 1 1 0 0 0;
  0 2 1 2 0 0;
  0 0 0 1 2 1;
  0 0 1 1 1 2;
  0 0 0 0 1 2;
];

pxA = 3;
pyA = 4;

pxB = 4;
pyB = 3;

pA = A(pxA, pyA);

disp("Matriz A - P-4");
P4A = [
0 A(pxA - 1, pyA) 0;
A(pxA, pyA - 1) pA A(pxA, pyA + 1);
0 A(pxA + 1, pyA) 0;
]

disp("Matriz A - P-D");
PDA = [
A(pxA - 1, pyA - 1) 0 A(pxA + 1, pyA + 1);
0 pA 0;
A(pxA + 1, pyA - 1) 0 A(pxA + 1, pyA + 1);
]

disp("Matriz A - P-8");
P8A = [
A(pxA - 1, pyA - 1) A(pxA - 1, pyA) A(pxA - 1, pyA + 1);
A(pxA, pyA - 1) pA A(pxA, pyA + 1);
A(pxA + 1, pyA - 1) A(pxA + 1, pyA) A(pxA + 1, pyA + 1);
]

pB = B(pxB, pyB);

disp("Matriz B - P-4");
P4B = [
0 B(pxB - 1, pyB) 0;
B(pxB, pyB - 1) pB B(pxB, pyB + 1);
0 B(pxB + 1, pyB) 0;
]

disp("Matriz B - P-D");
PDB = [
B(pxB - 1, pyB - 1) 0 B(pxB + 1, pyB + 1);
0 pB 0;
B(pxB + 1, pyB - 1) 0 B(pxB + 1, pyB + 1);
]

disp("Matriz B - P-8");
P8B = [
B(pxB - 1, pyB - 1) B(pxB - 1, pyB) B(pxB - 1, pyB + 1);
B(pxB, pyB - 1) pB B(pxB, pyB + 1);
B(pxB + 1, pyB - 1) B(pxB + 1, pyB) B(pxB + 1, pyB + 1);
]


