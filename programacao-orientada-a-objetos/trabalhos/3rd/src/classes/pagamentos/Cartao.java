package classes.pagamentos;

import classes.Cliente;
import classes.Pagamento;

public class Cartao extends Pagamento {
  Integer numero;
  String operadora;

  public Cartao() {
    super();
    setNumero(0);
    setOperadora("");
  }

  public Cartao(String d, Cliente c, Double v, Integer n, String o) {
    super(d, c, v);
    setNumero(n);
    setOperadora(o);
  }

  public Integer getNumero() {
    return numero;
  }

  public String getOperadora() {
    return operadora;
  }

  public void setNumero(Integer numero) {
    this.numero = numero;
  }

  public void setOperadora(String o) {
    this.operadora = o;
  }

  @Override
  public String toString() {
    return super.toString() +
           "\nPagamento: Cartão" +
           "\nNº Cartão: " + getNumero() +
           "\nOperadora: " + getOperadora();
  }
}
