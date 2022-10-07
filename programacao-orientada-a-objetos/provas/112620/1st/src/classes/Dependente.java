package classes;

public class Dependente extends Aluno {
  Double conceito;

  public Dependente(String n, Integer i, Double N, Double N1, Double N2, Double c) {
    super(n, i, N, N1, N2);
    setConceito(c);
  }

  @Override
  public String toString() {
    return super.toString() + 
           "\nConceito: " + this.getConceito();
  }
  
  public Double getConceito() {
    return this.conceito;
  }

  public void setConceito(Double conceito) {
    this.conceito = conceito;
  }

  @Override
  public Integer calculaMedia() {
    if(this.conceito < 3)
      return 0;
    else if(this.conceito < 5)
      return 1;
    else
      return 2;
  }
}
