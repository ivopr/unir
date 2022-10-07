package src.classes;

public class Cliente implements Autenticavel {
  String CPF, nome, senha;

  public Cliente() {
    setCPF("");
    setNome("");
    setSenha("");
  }

  public Cliente(String c, String n, String s) {
    setCPF(c);
    setNome(n);
    setSenha(s);
  }

  @Override
  public boolean auth(String senha) {
    return this.senha.equals(senha);
  }

  public String getCPF() {
    return CPF;
  }

  public String getNome() {
    return nome;
  }

  public String getSenha() {
    return senha;
  }

  public void setCPF(String cPF) {
    CPF = cPF;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public void setSenha(String senha) {
    this.senha = senha;
  }
}
