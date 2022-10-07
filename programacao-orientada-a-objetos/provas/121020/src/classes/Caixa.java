package src.classes;

public class Caixa implements Autenticavel {
  String nome, senha;
  Double salario;

  public Caixa() {
    setNome("");
    setSenha("");
    setSalario(0.0);
  }

  public Caixa(String n, String s, Double sr) {
    setNome(n);
    setSenha(s);
    setSalario(sr);
  }

  @Override
  public boolean auth(String senha) {
    return this.senha.equals(senha);
  }

  public String getNome() {
    return nome;
  }

  public Double getSalario() {
    return salario;
  }

  public String getSenha() {
    return senha;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setSalario(Double salario) {
    this.salario = salario;
  }
  
  public void setSenha(String senha) {
    this.senha = senha;
  }
}
