package classes.pagamentos;

import classes.Cliente;
import classes.Pagamento;

public class Dinheiro extends Pagamento {
  public Dinheiro() {
    super();
  }

  public Dinheiro(String d, Cliente c, Double v) {
    super(d, c, v);
  }

  @Override
  public String toString() {
    return super.toString() + 
           "\nPagamento: Dinheiro (à vista)";
  }
}
