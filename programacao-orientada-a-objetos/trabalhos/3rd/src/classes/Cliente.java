package classes;

public class Cliente {
  private String nome, endereco, cidade;

  public Cliente() {
    setNome("");
    setEndereco("");
    setCidade("");
  }

  public Cliente(String n, String e, String c) {
    setNome(n);
    setEndereco(e);
    setCidade(c);
  }

  public String getCidade() {
    return cidade;
  }

  public String getEndereco() {
    return endereco;
  }

  public String getNome() {
    return nome;
  }

  public void setCidade(String cidade) {
    this.cidade = cidade;
  }

  public void setEndereco(String endereco) {
    this.endereco = endereco;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  @Override
  public String toString() {
    return "Nome: " + getNome() +
           "\nEndereço: " + getEndereco() +
           "\nCidade: " + getCidade();
  }
}
