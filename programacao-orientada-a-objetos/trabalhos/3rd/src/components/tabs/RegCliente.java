package components.tabs;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import classes.Cliente;
import components.Campo;

public class RegCliente extends JComponent {
  private static final long serialVersionUID = 1L;

  public RegCliente(Vector<String> clientes, ArrayList<Cliente> lista) {
    setLayout(new BorderLayout());
    JPanel panel = new JPanel();
    panel.setLayout(new BoxLayout(panel, BoxLayout.Y_AXIS));
    Campo nome = new Campo("Nome");
    Campo endereco = new Campo("Endereço");
    Campo cidade = new Campo("Cidade");

    panel.setOpaque(false);

    panel.add(nome);
    panel.add(endereco);
    panel.add(cidade);

    JButton regCliente = new JButton("Cadastrar Cliente");
    regCliente.setBackground(Color.GRAY);
    regCliente.setForeground(Color.WHITE);

    JButton verCliente = new JButton("Exibir Clientes");
    verCliente.setBackground(Color.WHITE);
    verCliente.setForeground(Color.DARK_GRAY);

    JPanel buttons = new JPanel();
    buttons.setLayout(new FlowLayout());

    buttons.setOpaque(false);

    buttons.add(verCliente);
    buttons.add(regCliente);

    add(panel, BorderLayout.NORTH);
    add(buttons, BorderLayout.SOUTH);
    
    regCliente.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent a) {
        if(nome.getText().equals("") | endereco.getText().equals("") | cidade.getText().equals("")) {
          JOptionPane.showMessageDialog(null, "Todos os campos precisam ser preenchidos.", "ATENÇÃO", JOptionPane.WARNING_MESSAGE);
        } else {
          try {
            String n = nome.getText(), e = endereco.getText(), c = cidade.getText();
            Cliente cliente = new Cliente(n, e, c);
            lista.add(cliente);
            clientes.add(cliente.getNome());
            
            nome.cleanText();
            endereco.cleanText();
            cidade.cleanText();

            JOptionPane.showMessageDialog(null, "Cliente cadastrado!", "SUCESSO", JOptionPane.INFORMATION_MESSAGE);
          } catch(Exception e) {
            JOptionPane.showMessageDialog(null, e.getCause(), "ERRO", JOptionPane.ERROR_MESSAGE);
          }
        }
      }
    });

    verCliente.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent a) {
        if(lista.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há cliente cadastrado.", "ATENÇÃO", JOptionPane.WARNING_MESSAGE);
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
