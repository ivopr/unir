package src.classes;

public class ContaEspecial extends ContaSimples {
  Double limite;

  public ContaEspecial() {
    super();
    setLimite(0.0);
  }

  public ContaEspecial(String c, String nm, String s, String n, Double sd, Double l) {
    super(c, nm, s, n, sd);
    setLimite(l);
  }

  public Double getLimite() {
    return limite;
  }

  @Override
  public boolean saque(Double valor) {
    if(super.saque(valor))
      if(valor > limite) return false;
    return true;
  }

  public void setLimite(Double limite) {
    this.limite = limite;
  }

  @Override
  public String toString() {
    return  super.toString() +
            "\nLimite: R$ " + getLimite();
  }
}
