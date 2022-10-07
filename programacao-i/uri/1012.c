#include <stdio.h>
#include <math.h>
#define pi 3.14159
  double triangle(int a, int c) {
    double area = (a * c) / 2;
  return area;
  }
  double circle(int c) {
    double area = pi * pow(c, 2);
  return area;
  }
  double trapeze(int a, int b, int c) {
    double area = ((a * b) + (a * c)) / 2;
  return area;
  }
  double square(int b) {
    double area = pow(b, 2);
  return area;
  }
  double rectangle(int a, int b) {
    double area = a * b;
  return area;
  }
  int main() {
    double a, b, c;
    scanf("%lf %lf %lf", &a, &b, &c);
    printf("TRIANGULO: %.3lf\n", triangle(a, c));
    printf("CIRCULO: %.3lf\n", circle(c));
    printf("TRAPEZIO: %.3lf\n", trapeze(a, b, c));
    printf("QUADRADO: %.3lf\n", square(b));
    printf("RETANGULO: %.3lf\n", rectangle(a, b));
  return 0;
  }
