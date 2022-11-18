# Questão 1
# Seja um sistema de aritmética flutuante de quatro dígitos, base decimal e com
# acumulador de precisão dupla. Dados os números:

# Efetue as seguintes operações e obtenha o erro relativo no resultado, supondo que
# x, y e z estão exatamente representados.
# a. x + y + z
# b. x - y - z
# c. x/z
# d. (x * y)/z

x = 0.7234;
y = 0.00000002145;
z = 0.2585;

result = x + y + z;
relat_err = (result - 0.9819) / 0.9819;
printf("A) Resultado: %.2f\tErro Relativo: %.f\n", result, relat_err);

result = x - y - z;
relat_err = (result - 0.4649) / 0.4649;
printf("B) Resultado: %.2f\tErro Relativo: %.f\n", result, relat_err);

result = x / z;
relat_err = (result - 2.7984) / 2.7984;
printf("C) Resultado: %.2f\tErro Relativo: %.f\n", result, relat_err);

result = (x * y) / z;
relat_err = (result - 0.0000) / 0.0000;
printf("D) Resultado: %.2f\tErro Relativo: %.f\n", result, relat_err);
