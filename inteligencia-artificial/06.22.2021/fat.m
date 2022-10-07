function f = fat()

clc;
x = input('Digite um valor inteiro positivo: ');

f = x;
for i = 2 : x - 1 
    f = f * i;
end