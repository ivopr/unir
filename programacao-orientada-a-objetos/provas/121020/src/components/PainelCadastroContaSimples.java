package src.components;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import src.classes.Cliente;
import src.classes.ContaEspecial;
import src.classes.ContaSimples;

public class PainelCadastroContaSimples extends JPanel {
  private static final long serialVersionUID = 1L;
  private Campo cliente, numero, saldo;
  private JButton inserir;

  public PainelCadastroContaSimples(ArrayList<Cliente> listaClientes, ArrayList<ContaSimples> lista, ArrayList<ContaEspecial> listaEspecial) {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    cliente = new Campo("CPF do Cliente");
    numero = new Campo("Número");
    saldo = new Campo("Saldo");

    inserir = new JButton("Cadastrar");

    add(cliente);
    add(numero);
    add(saldo);
    add(inserir);

    inserir.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(cliente.getText().equals("") | numero.getText().equals("") | saldo.getText().equals("")) {
          JOptionPane.showMessageDialog(null, "Você deixou algum dos campos em branco.", "HALT!", JOptionPane.WARNING_MESSAGE);
        } else {
          Cliente cli = new Cliente();
          Integer guarda = 0;
          Double sc = 0.0;

          for(Cliente c : listaClientes) {
            if(c.getCPF().equals(cliente.getText()))
              cli = new Cliente(c.getCPF(), c.getNome(), c.getSenha());
          }

          for(ContaSimples cs : lista) {
            if(cs.getNumero().equals(numero.getText())) {
              guarda = 1;
            };
          }

          for(ContaEspecial ce : listaEspecial) {
            if(ce.getNumero().equals(numero.getText())) {
              guarda = 1;
            };
          }

          if(guarda == 1) {
            JOptionPane.showMessageDialog(null, "Este número de conta não está disponível", "HALT!", JOptionPane.ERROR_MESSAGE);
          } else {
            try {
              sc = Double.parseDouble(saldo.getText());

              if(cli.getNome().equals("") | cli.getCPF().equals("") | cli.getSenha().equals("")) {
                JOptionPane.showMessageDialog(null, "Ei, não temos nenhum cliente com esse CPF.", "HALT!", JOptionPane.ERROR_MESSAGE);
              } else {
                ContaSimples cs = new ContaSimples(cli.getCPF(), cli.getNome(), cli.getSenha(), numero.getText(), sc);
                lista.add(cs);
                JOptionPane.showMessageDialog(null, "Conta cadastrada!", "SUCESSO!", JOptionPane.INFORMATION_MESSAGE);
              }
            } catch(NumberFormatException ne) {
              JOptionPane.showMessageDialog(null, ne.getStackTrace(), "HALT!", JOptionPane.ERROR_MESSAGE);
            }
          }
        }
      }
    });
  }
}
