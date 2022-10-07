package src.elements;

public class Horista extends Empregado {
  private int horas;
  private double salario;

  public Horista() {
    super();
    this.horas = 0;
    this.salario = 0;
  }

  public Horista(String n, String d, int h, double s) {
    super(n, d);
    this.horas = h;
    this.salario = s;
  }

  public String toString() {
    return  super.toString() +
            "\nSalário/hora: " + this.getSalario() +
            "\nHoras Trabalhadas: " + this.getHoras() +
            "\nSalário Final: " + this.calculaSalario();
  }

  @Override
  public String getTipo() {
    return "Horista";
  }

  @Override
  public double calculaSalario() {
    if(this.horas <= 40) {
      return this.getHoras() * this.getSalario();
    } else {
      return (this.getSalario() * 40) + ((this.getHoras() - 40) * (this.getSalario() * 1.5));
    }
  }
  
  public void setHoras(int h) {
    this.horas = h;
  }

  public void setSalario(double s) {
    this.salario = s;
  }

  public int getHoras() {
    return this.horas;
  }

  public double getSalario() {
    return this.salario;
  }
}
