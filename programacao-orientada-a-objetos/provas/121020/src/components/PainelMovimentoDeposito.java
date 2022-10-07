package src.components;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

import src.classes.Auth;
import src.classes.ContaEspecial;
import src.classes.ContaSimples;

public class PainelMovimentoDeposito extends JPanel {
  private static final long serialVersionUID = 1L;
  private Campo conta, valor;
  private JButton inserir;

  public PainelMovimentoDeposito(ArrayList<ContaSimples> listaSimples, ArrayList<ContaEspecial> listaEspecial,
      ArrayList<Auth> listaAuth) {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    conta = new Campo("Nº da Conta");
    valor = new Campo("Valor");

    inserir = new JButton("Depositar");

    add(conta);
    add(valor);
    add(inserir);

    inserir.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(conta.getText().equals("") | valor.getText().equals("")) {
          JOptionPane.showMessageDialog(null, "Ei, você deixou algum campo em branco.", "HALT!", JOptionPane.ERROR_MESSAGE);
        } else {
          Double dv = 0.0;
          Integer guarda = 0;
          ContaSimples csim = new ContaSimples();
          ContaEspecial cesp = new ContaEspecial();

          for(ContaSimples cs : listaSimples) {
            if(cs.getNumero().equals(conta.getText())) {
              csim = cs;
              guarda = 1;
            }
          }
          
          if(csim.getCPF().equals("")) {
            for(ContaEspecial ce : listaEspecial) {
              if(ce.getNumero().equals(conta.getText())) {
                cesp = ce;
                guarda = 2;
              }
            }
          }

          if(guarda == 0) {
            JOptionPane.showMessageDialog(null, "Não temos registros de uma conta com esse número!", "HALT!", JOptionPane.ERROR_MESSAGE);
          } else {
            try {
              dv = Double.parseDouble(valor.getText());
  
              String senha = JOptionPane.showInputDialog(null, "Insira a senha da conta", JOptionPane.QUESTION_MESSAGE);
              
              if(guarda == 1) {
                if(csim.auth(senha)) {
                  csim.deposito(dv);
                  Auth a = new Auth("Depósito Conta Simples");
                  listaAuth.add(a);
                  JOptionPane.showMessageDialog(null, "Depósito efetuado.", "SUCESSO!", JOptionPane.INFORMATION_MESSAGE);
                } else {
                  JOptionPane.showMessageDialog(null, "Senha incorreta", "HALT!", JOptionPane.ERROR_MESSAGE);
                }
              } else if(guarda == 2) {
                if(cesp.auth(senha)) {
                  cesp.deposito(dv);
                  Auth a = new Auth("Depósito Conta Especial");
                  listaAuth.add(a);
                  JOptionPane.showMessageDialog(null, "Depósito efetuado.", "SUCESSO!", JOptionPane.INFORMATION_MESSAGE);
                } else {
                  JOptionPane.showMessageDialog(null, "Senha incorreta", "HALT!", JOptionPane.ERROR_MESSAGE);
                }
              }
            } catch(NumberFormatException ne) {
              JOptionPane.showMessageDialog(null, "Desculpe, não foi possível completar sua operação!", "HALT!", JOptionPane.ERROR_MESSAGE);
            }
          }
        }
      }
    });
  }
}
