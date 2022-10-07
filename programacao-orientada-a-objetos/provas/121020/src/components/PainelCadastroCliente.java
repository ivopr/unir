package src.components;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import src.classes.Cliente;

public class PainelCadastroCliente extends JPanel {
  private static final long serialVersionUID = 1L;
  private Campo cpf, nome, senha;
  private JButton inserir;

  public PainelCadastroCliente(ArrayList<Cliente> lista) {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    cpf = new Campo("CPF");
    nome = new Campo("Nome");
    senha = new Campo("Senha");

    inserir = new JButton("Cadastrar");

    add(cpf);
    add(nome);
    add(senha);
    add(inserir);

    inserir.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(cpf.getText().equals("") | nome.getText().equals("") | senha.getText().equals("")) {
          JOptionPane.showMessageDialog(null, "Você deixou algum dos campos em branco.", "HALT!", JOptionPane.WARNING_MESSAGE);
        } else {
          Boolean guarda = false;
          Cliente c = new Cliente(cpf.getText(), nome.getText(), senha.getText());
          for(int i = 0; i < lista.size(); i++) {
            if(lista.get(i).getCPF().equals(c.getCPF())) {
              guarda = true;
            }
          }

          if(guarda) {
            JOptionPane.showMessageDialog(null, "Ei, nós já temos um cliente com este CPF.", "HALT!", JOptionPane.ERROR_MESSAGE);
          } else {
            lista.add(c);
            JOptionPane.showMessageDialog(null, "Cliente Inserido!", "SUCESSO", JOptionPane.INFORMATION_MESSAGE);
          }
        }
      }
    });
  }
}
