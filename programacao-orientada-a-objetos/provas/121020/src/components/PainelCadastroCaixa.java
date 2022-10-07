package src.components;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JPanel;

public class PainelCadastroCaixa extends JPanel {
  private static final long serialVersionUID = 1L;
  private Campo nome, salario, senha;
  private JButton inserir;

  public PainelCadastroCaixa() {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    nome = new Campo("Nome");
    salario = new Campo("Salário");
    senha = new Campo("Senha");

    inserir = new JButton("Cadastrar");

    add(nome);
    add(salario);
    add(senha);
    add(inserir);
  }
}
