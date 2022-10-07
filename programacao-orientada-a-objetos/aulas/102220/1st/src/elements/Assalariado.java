package src.elements;

public class Assalariado extends Empregado {
  private double salario, desconto;

  public Assalariado() {
    super();
    this.salario = this.desconto = 0;
  }

  public Assalariado(String n, String d, double s, double desc) {
    super(n, d);
    this.salario = s;
    this.desconto = desc;
  }

  public String toString() {
    return  super.toString() + 
            "\nSalário: " + this.getSalario() + 
            "\nDesconto: " + this.getDesconto() +
            "\nSalário final: " + this.calculaSalario();
  }

  @Override
  public String getTipo() {
    return "Assalariado";
  }

  @Override
  public double calculaSalario() {
    return this.getSalario() - this.getDesconto();
  }

  public void setSalario(double s) {
    this.salario = s;
  }

  public void setDesconto(double d) {
    this.desconto = d;
  }

  public double getSalario() {
    return this.salario;
  }

  public double getDesconto() {
    return this.desconto;
  }
}
