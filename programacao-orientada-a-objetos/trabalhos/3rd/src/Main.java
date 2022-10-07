import java.awt.BorderLayout;
import java.awt.Dimension;
import java.util.ArrayList;
import java.util.Vector;

import javax.swing.JFrame;
import javax.swing.JTabbedPane;

import classes.Cliente;
import classes.Pagamento;
import components.tabs.RegCliente;
import components.tabs.RegPagamento;

public class Main extends JFrame {
  private static final long serialVersionUID = 4648172894076113183L;
  private ArrayList<Cliente> listaClientes = new ArrayList<Cliente>();
  private ArrayList<Pagamento> listaPagamentos = new ArrayList<Pagamento>();
  Vector<String> clientes = new Vector<String>();

  public Main() {
    setTitle("PagNÃOSeguro - Trabalho 3");
    setLayout(new BorderLayout());
    clientes.add("Selecione um cliente");
    JTabbedPane tabbed = new JTabbedPane();
    RegCliente tabCliente = new RegCliente(clientes, listaClientes);
    RegPagamento tabPagamento = new RegPagamento(listaClientes, clientes, listaPagamentos);
    tabbed.addTab("Cadastro Cliente", tabCliente);
    tabbed.addTab("Pagamento do Cliente", tabPagamento);
    add(tabbed);
  }
  
  public static void main(String[] args) {
    Main m = new Main();
    m.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    m.pack();
    m.setMinimumSize(new Dimension(384, 100));
    m.setLocationRelativeTo(null);
    m.setVisible(true);
  }
}