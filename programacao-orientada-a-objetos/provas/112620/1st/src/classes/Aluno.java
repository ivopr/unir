package classes;

public class Aluno extends Pessoa {
  Double n, n1, n2, m;

  public Aluno(String n, Integer i, Double N, Double N1, Double N2) {
    super(n, i);
    setN(N);
    setN1(N1);
    setN2(N2);
    setM();
  }

  @Override
  public String toString() {
    return super.toString() + 
           "\nNota 1: " + this.getN() +
           "\nNota 2: " + this.getN1() + 
           "\nNota 3: " + this.getN2() +
           "\nMedia: " + this.getM();
  }

  public Double getN() {
    return this.n;
  }

  public Double getN1() {
    return this.n1;
  }

  public Double getN2() {
    return this.n2;
  }

  public Double getM() {
    return this.m;
  }

  public void setN(Double n) {
    this.n = n;
  }

  public void setN1(Double n1) {
    this.n1 = n1;
  }

  public void setN2(Double n2) {
    this.n2 = n2;
  }

  public void setM() {
    this.m = (this.getN() + this.getN1() + this.getN2()) / 3;
  }

  public Integer calculaMedia() {
    if(this.m < 3)
      return 0;
    else if(this.m < 5)
      return 1;
    else
      return 2;
  }
}
