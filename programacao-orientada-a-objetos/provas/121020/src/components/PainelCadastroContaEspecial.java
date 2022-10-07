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

public class PainelCadastroContaEspecial extends JPanel {
  private static final long serialVersionUID = 1L;
  private Campo cliente, numero, saldo, limite;
  private JButton inserir;

  public PainelCadastroContaEspecial(ArrayList<Cliente> listaClientes, ArrayList<ContaEspecial> lista, ArrayList<ContaSimples> listaSimples) {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    cliente = new Campo("Cliente");
    numero = new Campo("Número");
    saldo = new Campo("Saldo");
    limite = new Campo("Limite");

    inserir = new JButton("Cadastrar");

    add(cliente);
    add(numero);
    add(saldo);
    add(limite);
    add(inserir);

    inserir.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(cliente.getText().equals("") | numero.getText().equals("") | saldo.getText().equals("") | limite.getText().equals("")) {
          JOptionPane.showMessageDialog(null, "Você deixou algum dos campos em branco.", "HALT!", JOptionPane.WARNING_MESSAGE);
        } else {
          Cliente cli = new Cliente();
          Integer guarda = 0;
          Double lc = 0.0, sc = 0.0;

          for(Cliente c : listaClientes) {
            if(c.getCPF().equals(cliente.getText()))
              cli = c;
          }

            for(ContaSimples cs : listaSimples) {
              if(cs.getNumero().equals(numero.getText())) {
                guarda = 1;
              };
            }

            for(ContaEspecial ce : lista) {
              if(ce.getNumero().equals(numero.getText())) {
                guarda = 1;
              };
            }

            if(guarda == 1) {
              JOptionPane.showMessageDialog(null, "Este número de conta não está disponível", "HALT!", JOptionPane.ERROR_MESSAGE);
            } else {
              try {
                sc = Double.parseDouble(saldo.getText());

                try {
                  lc = Double.parseDouble(limite.getText());

                  if(cli.getNome().equals("") | cli.getCPF().equals("") | cli.getSenha().equals("")) {
                    JOptionPane.showMessageDialog(null, "Ei, não temos nenhum cliente com esse CPF.", "HALT!", JOptionPane.ERROR_MESSAGE);
                  } else {
                    ContaEspecial cs = new ContaEspecial(cli.getCPF(), cli.getNome(), cli.getSenha(), numero.getText(), sc, lc);
                    lista.add(cs);
                    JOptionPane.showMessageDialog(null, "Conta cadastrada!", "SUCESSO!", JOptionPane.INFORMATION_MESSAGE);
                  }
                } catch(NumberFormatException ne) {
                  JOptionPane.showMessageDialog(null, ne.getStackTrace(), "HALT!", JOptionPane.ERROR_MESSAGE);
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
