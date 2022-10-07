package classes;

import java.util.UUID;

public abstract class Pagamento {
  String data, id;
  Cliente cliente;
  Double valor;

  public Pagamento() {
    setData("");
    setCliente(null);
    setValor(0.0);
  }

  public Pagamento(String d, Cliente c, Double v) {
    setData(d);
    setCliente(c);
    setValor(v);
    setID();
  }

  public Cliente getCliente() {
    return cliente;
  }

  public String getData() {
    return data;
  }

  public String getID() {
    return id;
  }

  public Double getValor() {
    return valor;
  }

  public void setCliente(Cliente cliente) {
    this.cliente = cliente;
  }

  public void setData(String data) {
    this.data = data;
  }

  public void setID() {
    this.id = UUID.randomUUID().toString();
  }
  
  public void setValor(Double valor) {
    this.valor = valor;
  }

  @Override
  public String toString() {
    return "ID: " + getID() +
           "\nData: " + getData() +
           "\nCliente: " + getCliente().getNome() +
           "\nValor: " + getValor();
  }
}
