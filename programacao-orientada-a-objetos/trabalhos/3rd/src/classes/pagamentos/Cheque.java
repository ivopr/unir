package classes.pagamentos;

import classes.Cliente;
import classes.Pagamento;

public class Cheque extends Pagamento {
  Integer numero;
  String banco;

  public Cheque() {
    super();
    setNumero(0);
    setBanco("");
  }

  public Cheque(String d, Cliente c, Double v, Integer n, String b) {
    super(d, c, v);
    setNumero(n);
    setBanco(b);
  }

  public String getBanco() {
    return banco;
  }
  

  public Integer getNumero() {
    return numero;
  }

  public void setBanco(String b) {
    this.banco = b;
  }

  public void setNumero(Integer numero) {
    this.numero = numero;
  }

  @Override
  public String toString() {
    return super.toString() +
           "\nPagamento: Cheque" +
           "\nNº Cheque: " + getNumero() +
           "\nBanco: " + getBanco();
  }
}
