package src.classes;

public class ContaSimples extends Cliente {
  Cliente cliente;
  String numero;
  Double saldo;

  public ContaSimples() {
    super();
    setNumero("");
    setSaldo(0.0);
  }

  public ContaSimples(String c, String nm, String s, String n, Double sd) {
    super(c, nm, s);
    setNumero(n);
    setSaldo(sd);
  }

  public void deposito(Double valor) {
    saldo += valor;
  }

  public String getNumero() {
    return numero;
  }

  public Double getSaldo() {
    return saldo;
  }

  public boolean saque(Double valor) {
    if(valor > saldo) return false;
    saldo -= valor;
    return true;
  }

  public void setNumero(String numero) {
    this.numero = numero;
  }

  public void setSaldo(Double saldo) {
    this.saldo = saldo;
  }

  @Override
  public String toString() {
    return  "Número: " + getNumero() +
            "\nCliente: " + super.getNome() +
            "\nSaldo: R$ " + getSaldo();
  }
}
