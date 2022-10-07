package src.classes;

import java.sql.Timestamp;
import java.util.Date;
import java.util.UUID;

public class Auth {
  private Timestamp time;
  private String id, operacao;

  public Auth(String o) {
    setTime();
    setId();
    setOperacao(o);
  }

  public String getId() {
    return id;
  }

  public String getOperacao() {
    return operacao;
  }

  public Timestamp getTime() {
    return time;
  }
  
  public void setTime() {
    this.time = new Timestamp(new Date().getTime());
  }

  public void setId() {
    this.id = UUID.randomUUID().toString();
  }

  public void setOperacao(String operacao) {
    this.operacao = operacao;
  }

  @Override
  public String toString() {
    return  "ID: " + getId() +
            "\nTimestamp: " + getTime() +
            "\nOperação: " + getOperacao();
  }
}
