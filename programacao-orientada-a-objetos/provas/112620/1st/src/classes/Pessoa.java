package classes;

public abstract class Pessoa {
  String name;
  Integer idade;

  Pessoa(String n, Integer i) {
    this.setName(n);
    this.setIdade(i);
  }

  @Override
  public String toString() {
    return "Nome: " + this.name +
           "\nIdade: " + this.idade + " anos";
  }

  public Integer getIdade() {
    return this.idade;
  }

  public String getName() {
    return this.name;
  }
  
  public void setIdade(Integer idade) {
    this.idade = idade;
  }

  public void setName(String name) {
    this.name = name;
  }
}
