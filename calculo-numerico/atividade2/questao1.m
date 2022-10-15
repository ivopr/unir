# Questão 1

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
