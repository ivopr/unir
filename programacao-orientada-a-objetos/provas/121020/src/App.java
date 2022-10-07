package src;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;

import javax.imageio.ImageIO;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

import src.classes.Auth;
import src.classes.Cliente;
import src.classes.ContaEspecial;
import src.classes.ContaSimples;
import src.components.PainelCadastroCaixa;
import src.components.PainelCadastroCliente;
import src.components.PainelCadastroContaEspecial;
import src.components.PainelCadastroContaSimples;
import src.components.PainelMovimentoDeposito;
import src.components.PainelMovimentoSaque;

public class App extends JFrame {
  private static final long serialVersionUID = 1L;
  private JMenuBar menubar;
  private JMenu cadastro, movimento, relatorio, sair;
  private JMenuItem cadastroCaixa, cadastroCliente, cadastroContaSimples, cadastroContaEspecial, movimentoSaque,
      movimentoDeposito, relatorioAutenticacoes, relatorioClientes, sairPrograma;
  private ArrayList<Cliente> listaClientes = new ArrayList<Cliente>();
  private ArrayList<ContaSimples> listaContaSimples = new ArrayList<ContaSimples>();
  private ArrayList<ContaEspecial> listaContaEspecial = new ArrayList<ContaEspecial>();
  private ArrayList<Auth> listaAuth = new ArrayList<Auth>();

  public App() {
    super("Banco Tabajara");
    setLayout(new BorderLayout());

    menubar = new JMenuBar();

    // JMenu
    cadastro = new JMenu("Cadastro");
    movimento = new JMenu("Movimento");
    relatorio = new JMenu("Relatórios");
    sair = new JMenu("Sair");

    // JMenuItem
    cadastroCaixa = new JMenuItem("Caixa");
    cadastroCliente = new JMenuItem("Cliente");
    cadastroContaSimples = new JMenuItem("Conta Simples");
    cadastroContaEspecial = new JMenuItem("Conta Especial");
    movimentoSaque = new JMenuItem("Saque");
    movimentoDeposito = new JMenuItem("Depósito");
    relatorioAutenticacoes = new JMenuItem("Autenticações");
    relatorioClientes = new JMenuItem("Clientes");
    sairPrograma = new JMenuItem("Encerrar Programa");

    // Adicionar itens no menu
    cadastro.add(cadastroCaixa);
    cadastro.add(cadastroCliente);
    cadastro.add(cadastroContaSimples);
    cadastro.add(cadastroContaEspecial);

    movimento.add(movimentoSaque);
    movimento.add(movimentoDeposito);

    relatorio.add(relatorioAutenticacoes);
    relatorio.add(relatorioClientes);

    sair.add(sairPrograma);

    menubar.add(cadastro);
    menubar.add(movimento);
    menubar.add(relatorio);
    menubar.add(sair);

    setJMenuBar(menubar);

    JPanel home = new JPanel();
    BufferedImage img = null;
    try {
      img = ImageIO.read(new File("src/dinheiros.jpg"));
    } catch (IOException e1) {
      e1.printStackTrace();
    }

    JLabel imglbl = new JLabel(new ImageIcon(img));

    home.add(imglbl);

    add(home);

    cadastroCaixa.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelCadastroCaixa painelCaixa = new PainelCadastroCaixa();
        getContentPane().add(painelCaixa);
        revalidate();
        repaint();
        pack();
      }
    });

    cadastroCliente.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelCadastroCliente painelCliente = new PainelCadastroCliente(listaClientes);
        getContentPane().add(painelCliente);
        revalidate();
        repaint();
        pack();
      }
    });

    cadastroContaSimples.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelCadastroContaSimples painelContaSimples = new PainelCadastroContaSimples(listaClientes, listaContaSimples, listaContaEspecial);
        getContentPane().add(painelContaSimples);
        revalidate();
        repaint();
        pack();
      }
    });

    cadastroContaEspecial.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelCadastroContaEspecial painelContaEspecial = new PainelCadastroContaEspecial(listaClientes, listaContaEspecial, listaContaSimples);
        getContentPane().add(painelContaEspecial);
        revalidate();
        repaint();
        pack();
      }
    });

    movimentoDeposito.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelMovimentoDeposito painelMovimentoDeposito = new PainelMovimentoDeposito(listaContaSimples, listaContaEspecial, listaAuth);
        getContentPane().add(painelMovimentoDeposito);
        revalidate();
        repaint();
        pack();
      }
    });

    movimentoSaque.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        getContentPane().removeAll();
        PainelMovimentoSaque painelMovimentoSaque = new PainelMovimentoSaque(listaContaSimples, listaContaEspecial, listaAuth);
        getContentPane().add(painelMovimentoSaque);
        revalidate();
        repaint();
        pack();
      }
    });

    relatorioAutenticacoes.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(listaAuth.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há registro de autenticações.", "ATENÇÃO", JOptionPane.WARNING_MESSAGE);
        } else {
          String saida = "";
          for(Integer i = 0; i < listaAuth.size(); i++) {
            if(i == 0) {
              saida += listaAuth.get(i).toString();
            } else {
              saida += "\n\n" + listaAuth.get(i).toString();
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

    relatorioClientes.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        if(listaContaEspecial.isEmpty() && listaContaSimples.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há contas cadastradas.", "ATENÇÃO", JOptionPane.WARNING_MESSAGE);
        } else {
          String saida = "";
          for(Integer i = 0; i < listaContaSimples.size(); i++) {
            if(i == 0) {
              saida += listaContaSimples.get(i).toString();
            } else {
              saida += "\n\n" + listaContaSimples.get(i).toString();
            }
          }
          for(Integer i = 0; i < listaContaEspecial.size(); i++) {
            saida += "\n\n" + listaContaEspecial.get(i).toString();
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

    sairPrograma.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        System.exit(0);
      }
    });
  }

  public static void main(String[] args) {
    App a = new App();
    a.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    a.pack();
    a.setLocationRelativeTo(null);
    a.setVisible(true);
  }
}