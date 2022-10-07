package components.tabs;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import classes.Cliente;
import classes.Pagamento;
import classes.pagamentos.Cartao;
import classes.pagamentos.Cheque;
import classes.pagamentos.Dinheiro;
import components.tabs.pagamento.Centro;
import components.tabs.pagamento.Norte;

public class RegPagamento extends JComponent {
  private static final long serialVersionUID = 1L;

  public RegPagamento(ArrayList<Cliente> listaClientes, Vector<String> clientes, ArrayList<Pagamento> lista) {
    setLayout(new BorderLayout());

    Norte painelNorte = new Norte(clientes);

    JButton regPagamento = new JButton("Cadastrar Pagamento");
    regPagamento.setBackground(Color.GRAY);
    regPagamento.setForeground(Color.WHITE);

    JButton verPagamento = new JButton("Exibir Pagamentos");
    verPagamento.setBackground(Color.WHITE);
    verPagamento.setForeground(Color.DARK_GRAY);

    JPanel buttons = new JPanel();
    buttons.setLayout(new FlowLayout());

    buttons.setOpaque(false);

    buttons.add(verPagamento);
    buttons.add(regPagamento);

    Centro painelCentro = new Centro();

    add(painelNorte, BorderLayout.NORTH);
    add(painelCentro, BorderLayout.CENTER);
    add(buttons, BorderLayout.SOUTH);
    
    regPagamento.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent a) {
        Cliente selected = new Cliente();
        for(int i = 0; i < listaClientes.size(); i ++) {
          if(listaClientes.get(i).getNome() == painelNorte.getSelectedClient()) {
            selected = listaClientes.get(i);
            break;
          }
        }
        if(selected.getNome().isEmpty()) {
          JOptionPane.showMessageDialog(null, "Selecione o cliente.", "ERRO", JOptionPane.ERROR_MESSAGE);
        } else {
          if(painelNorte.getData().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Se você vai pagar, tem que ter ocorrido em algum momento passado, e não em um momento inexistente.", "ERRO", JOptionPane.ERROR_MESSAGE);
          } else {
            if(painelNorte.getValor() <= 0) {
              JOptionPane.showMessageDialog(null, "Não é possível fazer um pagamento inverso (Somos uma empresa privada, é você quem tem que nos pagar).", "ERRO", JOptionPane.ERROR_MESSAGE);
            } else {
              // 1 - Cartão | 2 - Cheque | 3 - Dinheiro
              switch(painelCentro.getSelectedPayment()) {
                case 1: {
                  Integer nc = -1;
                  String[] data = painelCentro.getCartaoData();
  
                  try {
                    nc = Integer.parseInt(data[0]);
                  } catch(NumberFormatException e) {
                    JOptionPane.showMessageDialog(null, "Número de cartão inválido", "ERRO", JOptionPane.ERROR_MESSAGE);
                  }
                  
                  if(nc != -1) {
                    Cartao novo = new Cartao(painelNorte.getData(), selected, painelNorte.getValor(), nc, data[1]);
                    lista.add(novo);
                    JOptionPane.showMessageDialog(null, "Pagamento efetuado!", "SUCESSO", JOptionPane.INFORMATION_MESSAGE);
                  
                    painelNorte.limparTexto();
                    painelCentro.limparTexto();
                  }
  
                  break;
                }
                case 2: {
                  Integer nc = -1;
                  String[] data = painelCentro.getChequeData();
  
                  try {
                    nc = Integer.parseInt(data[0]);
                  } catch(NumberFormatException e) {
                    JOptionPane.showMessageDialog(null, "Nº de Cheque inválido!", "ERRO", JOptionPane.ERROR_MESSAGE);
                  }
  
                  if(nc != -1) {
                    Cheque novo = new Cheque(painelNorte.getData(), selected, painelNorte.getValor(), nc, data[1]);
                    lista.add(novo);
                    JOptionPane.showMessageDialog(null, "Pagamento efetuado!", "SUCESSO", JOptionPane.INFORMATION_MESSAGE);
                  
                    painelNorte.limparTexto();
                    painelCentro.limparTexto();
                  }
                  break;
                }
                case 3: {
                  Dinheiro novo = new Dinheiro(painelNorte.getData(), selected, painelNorte.getValor());
                  lista.add(novo);
                  JOptionPane.showMessageDialog(null, "Pagamento efetuado!", "SUCESSO", JOptionPane.INFORMATION_MESSAGE);
                  painelNorte.limparTexto();
                  break;
                }
              }
            }
          }
        }
      }
    });

    verPagamento.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent a) {
        if(lista.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há pagamento cadastrado.", "ATENÇÃO", JOptionPane.WARNING_MESSAGE);
        } else {
          String saida = "";
          for(Integer i = 0; i < lista.size(); i++) {
            if(i == 0) {
              saida += lista.get(i).toString();
            } else {
              saida += "\n\n" + lista.get(i).toString();
            }
          }
          JTextArea out = new JTextArea(saida);
          out.setEditable(false);
          out.setOpaque(false);
          out.setBorder(null);
          JScrollPane scrollPane = new JScrollPane(out);
          scrollPane.setPreferredSize(new Dimension(384, 158));
          JOptionPane.showMessageDialog(null, scrollPane, "Lista de Clientes", JOptionPane.PLAIN_MESSAGE);
        }
      }
    });
  }
}
