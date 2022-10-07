package src.elements;

public class Comissionado extends Empregado {
  private double vendas, comissao, bonus;

  public Comissionado() {
    super();
    this.vendas = this.comissao = this.bonus = 0;
  }

  public Comissionado(String n, String d, double v, double c, double b) {
    super(n, d);
    this.vendas = v;
    this.comissao = c;
    this.bonus = b;
  }

  public String toString() {
    return  super.toString() +
            "\nTotal Vendas: " + this.getVendas() +
            "\nTaxa Comissão: " + this.getComissao() +
            "\nBonus: " + this.getBonus() +
            "\nSalário Final: " + this.calculaSalario();
  }

  @Override
  public String getTipo() {
    return "Comissionado";
  }

  @Override
  public double calculaSalario() {
    return (this.getVendas() * this.getComissao()) + this.getBonus();
  }
  
  public void setVendas(double v) {
    this.vendas = v;
  }

  public void setComissao(double c) {
    this.comissao = c;
  }

  public void setBonus(double b) {
    this.bonus = b;
  }

  public double getVendas() {
    return this.vendas;
  }

  public double getComissao() {
    return this.comissao;
  }

  public double getBonus() {
    return this.bonus;
  }
}
