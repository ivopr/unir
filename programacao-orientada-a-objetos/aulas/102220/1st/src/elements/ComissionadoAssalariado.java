package src.elements;

public class ComissionadoAssalariado extends Comissionado {
  private double salarioBase;

  public ComissionadoAssalariado() {
    super();
    this.salarioBase = 0;
  }

  public ComissionadoAssalariado(String n, String d, double v, double c, double b, double s) {
    super(n, d, v, c, b);
    this.salarioBase = s;
  }

  @Override
  public String getTipo() {
    return "Comissionado Assalariado";
  }

  @Override
  public double calculaSalario() {
    return this.getSalario() + super.calculaSalario();
  }

  public void setSalario(double s) {
    this.salarioBase = s;
  }

  public double getSalario() {
    return this.salarioBase;
  }
}
