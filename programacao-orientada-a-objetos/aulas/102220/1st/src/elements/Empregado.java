package src.elements;

public abstract class Empregado {
  private String nome, departamento;

  public Empregado() {
    this.nome = departamento = "";
  }

  public Empregado(String n, String d) {
    this.nome = n;
    this.departamento = d;
  }

  public abstract double calculaSalario();
  public abstract String getTipo();

  public String toString() {
    return  "Nome: " + this.getNome() + 
            "\nDepartamento: " + this.getDepartamento() +
            "\nTipo: " + this.getTipo();
  }

  public void setDepartamento(String d) {
    this.departamento = d;
  }

  public void setNome(String n) {
    this.nome = n;
  }

  public String getDepartamento() {
    return this.departamento;
  }

  public String getNome() {
    return this.nome;
  }
}
