import classes.Aluno;
import classes.Dependente;
import classes.Pessoa;
import components.Campo;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JDesktopPane;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class App extends JFrame {
  private static final long serialVersionUID = 1L;
  private Campo nome, idade, nota, nota1, nota2, conceito;
  private JButton biAluno, biDependente;
  private JMenuBar menubar;
  private JMenu inserir, relatorio, limpar, sair;
  private JMenuItem iAluno, iDependente, sProg, rAluno, rDependente, lText;
  private JDesktopPane janela;
  private JPanel jpAluno, jpDependente, jpInicio;
  private ArrayList<Pessoa> lista = new ArrayList<Pessoa>();

  App() {
    super("Isso é uma escola?");
    setLayout(new BorderLayout());
    janela = new JDesktopPane();
    janela.setLayout(new BorderLayout());

    menubar = new JMenuBar();
    setJMenuBar(menubar);

    inserir = new JMenu("Inserir");
    relatorio = new JMenu("Relatórios");
    limpar = new JMenu("Limpar");
    sair = new JMenu("Sair");

    iAluno = new JMenuItem("Aluno");
    iDependente = new JMenuItem("Dependente");

    inserir.add(iAluno);
    inserir.add(iDependente);

    lText = new JMenuItem("Limpar Tudo");
    limpar.add(lText);

    sProg = new JMenuItem("Fechar Programa");
    sair.add(sProg);

    rAluno = new JMenuItem("Alunos");
    rDependente = new JMenuItem("Dependentes");
    relatorio.add(rAluno);
    relatorio.add(rDependente);

    menubar.add(inserir);
    menubar.add(relatorio);
    menubar.add(limpar);
    menubar.add(sair);

    nome = new Campo("Nome", 10);
    idade = new Campo("Idade", 10);

    eventoInserir funcI = new eventoInserir();
    iAluno.addActionListener(funcI);
    iDependente.addActionListener(funcI);

    eventoRelatorio funcR = new eventoRelatorio();
    rAluno.addActionListener(funcR);
    rDependente.addActionListener(funcR);

    eventoLimpar funcL = new eventoLimpar();
    lText.addActionListener(funcL);

    eventoSair funcS = new eventoSair();
    sProg.addActionListener(funcS);

    jpInicio = new JPanel();
    jpInicio.setLayout(new BoxLayout(jpInicio, BoxLayout.Y_AXIS));
    JLabel init = new JLabel("Olha o menuzinho ali em cima.");
    JLabel init1 = new JLabel("Não adianta inserir letra na nota pois não passarás.");
    jpInicio.setBorder(javax.swing.BorderFactory.createTitledBorder("Bem-vindo (a)"));
    jpInicio.add(init);
    jpInicio.add(init1);
    add(jpInicio);
  }

  private class eventoInserir implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
      getContentPane().removeAll();
      if(e.getSource() == iAluno) {
        JPanel panel = new panelAluno();
        getContentPane().add(panel);
      } else if(e.getSource() == iDependente) {
        JPanel panel = new panelDependente();
        getContentPane().add(panel);
      }
      revalidate();
      repaint();
      pack();
    }
  }

  private class panelAluno extends JPanel {
    private static final long serialVersionUID = 1L;
    
    public panelAluno() {
      nome.resetValue();
      idade.resetValue();
      jpAluno = new JPanel();
      jpAluno.setLayout(new BoxLayout(jpAluno, BoxLayout.Y_AXIS));
      jpAluno.setBorder(javax.swing.BorderFactory.createTitledBorder("Inserir Aluno"));
      nota = new Campo("Nota 1:", 10);
      nota1 = new Campo("Nota 2:", 10);
      nota2 = new Campo("Nota 3:", 10);
      biAluno = new JButton("Inserir");
      jpAluno.add(nome);
      jpAluno.add(idade);
      jpAluno.add(nota);
      jpAluno.add(nota1);
      jpAluno.add(nota2);
      jpAluno.add(biAluno);
      add(jpAluno);

      biAluno.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          String n, i, no, no1, no2;
          Double not = 0.0, not1 = 0.0, not2 = 0.0;
          Integer idad = 0;
          Boolean pass = true;
          n = nome.getValue();
          i = idade.getValue();
          no = nota.getValue();
          no1 = nota1.getValue();
          no2 = nota2.getValue();
          

          if(n.equals("") | i.equals("") | no.equals("") | no1.equals("") | no2.equals("")) {
            JOptionPane.showMessageDialog(null, "Preencha todos os campos", "ERRO", JOptionPane.PLAIN_MESSAGE);
          } else {
            try {
              idad = Integer.parseInt(i);
            } catch(Exception exc) {
              idade.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a idade.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            try {
              not = Double.parseDouble(no);
            } catch(Exception exc) {
              nota.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 1.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }
            
            try {
              not1 = Double.parseDouble(no1);
            } catch(Exception exc) {
              nota1.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 2.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }     

            try {
              not2 = Double.parseDouble(no2);
            } catch(Exception exc) {
              nota2.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 3.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            if(not < 0 | not1 < 0 | not2 < 0) {
              nota.resetValue();
              nota1.resetValue();
              nota2.resetValue();
              pass = false;
            }

            if(!pass) {
              JOptionPane.showMessageDialog(null, "Não é possível inserir notas negativas.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            } else {
              Aluno al = new Aluno(n, idad, not, not1, not2);
              lista.add(al);
              JOptionPane.showMessageDialog(null, "O Aluno foi inserido.", "SUCESSO", JOptionPane.PLAIN_MESSAGE);
            
              nome.resetValue();
              idade.resetValue();
              nota.resetValue();
              nota1.resetValue();
              nota2.resetValue();
            }
          }
        }
      });
    }
  }

  private class panelDependente extends JPanel {
    private static final long serialVersionUID = 1L;
    
    public panelDependente() {
      nome.resetValue();
      idade.resetValue();
      jpDependente = new JPanel();
      jpDependente.setLayout(new BoxLayout(jpDependente, BoxLayout.Y_AXIS));
      jpDependente.setBorder(javax.swing.BorderFactory.createTitledBorder("Inserir Aluno Dependente"));
      nota = new Campo("Nota 1:", 10);
      nota1 = new Campo("Nota 2:", 10);
      nota2 = new Campo("Nota 3:", 10);
      conceito = new Campo("Conceito:", 10);
      biDependente = new JButton("Inserir");
      jpDependente.add(nome);
      jpDependente.add(idade);
      jpDependente.add(nota);
      jpDependente.add(nota1);
      jpDependente.add(nota2);
      jpDependente.add(conceito);
      jpDependente.add(biDependente);
      add(jpDependente);

      biDependente.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent e) {
          String n, i, no, no1, no2, con;
          Double not = 0.0, not1 = 0.0, not2 = 0.0, conc = 0.0;
          Integer idad = 0;
          Boolean pass = true;
          n = nome.getValue();
          i = idade.getValue();
          no = nota.getValue();
          no1 = nota1.getValue();
          no2 = nota2.getValue();
          con = conceito.getValue();
          

          if(n.equals("") | i.equals("") | no.equals("") | no1.equals("") | no2.equals("") | con.equals("")) {
            JOptionPane.showMessageDialog(null, "Preencha todos os campos", "ERRO", JOptionPane.PLAIN_MESSAGE);
          } else {
            try {
              idad = Integer.parseInt(i);
            } catch(Exception exc) {
              idade.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a idade.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            try {
              not = Double.parseDouble(no);
            } catch(Exception exc) {
              nota.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 1.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }
            
            try {
              not1 = Double.parseDouble(no1);
            } catch(Exception exc) {
              nota1.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 2.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            try {
              not2 = Double.parseDouble(no2);
            } catch(Exception exc) {
              nota2.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi a nota 3.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            try {
              conc = Double.parseDouble(con);
            } catch(Exception exc) {
              conceito.resetValue();
              JOptionPane.showMessageDialog(null, "Desculpe, não entendi o conceito.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            }

            if(not < 0 | not1 < 0 | not2 < 0) {
              nota.resetValue();
              nota1.resetValue();
              nota2.resetValue();
              conceito.resetValue();
              pass = false;
            }

            if(!pass) {
              JOptionPane.showMessageDialog(null, "Não é possível inserir notas negativas.", "ERRO", JOptionPane.PLAIN_MESSAGE);
            } else {
              Dependente dep = new Dependente(n, idad, not, not1, not2, conc);
              if(dep.getM() < 5) {
                JOptionPane.showMessageDialog(null, "Seu aluno dependente tem nota o suficiente pra ser aprovado... ué...", "ERRO", JOptionPane.PLAIN_MESSAGE);
              } else {
                lista.add(dep);
                JOptionPane.showMessageDialog(null, "O Aluno Dependente foi inserido.", "SUCESSO", JOptionPane.PLAIN_MESSAGE);
              }

              nome.resetValue();
              idade.resetValue();
              nota.resetValue();
              nota1.resetValue();
              nota2.resetValue();
              conceito.resetValue();
            }
          }
        }
      });
    }
  }

  private class eventoLimpar implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
      if(e.getSource() == lText) {
        nome.resetValue();
        idade.resetValue();
        nota.resetValue();
        nota1.resetValue();
        nota2.resetValue();
        conceito.resetValue();
      }
    }
  }

  private class eventoSair implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
      if(e.getSource() == sProg) {
        System.exit(0);
      }
    }
  }

  private class eventoRelatorio implements ActionListener {
    @Override
    public void actionPerformed(ActionEvent e) {
      if(e.getSource() == rAluno) {
        if(lista.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há um aluno na lista.", "ATENÇÃO", JOptionPane.PLAIN_MESSAGE);
        } else {
          String saida = "", sit = "";
          for(int i = 0; i < lista.size(); i++) {
            if(lista.get(i) instanceof Aluno) {
              if(((Aluno) lista.get(i)).calculaMedia() == 0) {
                sit = "Reprovado";
              } else if(((Aluno) lista.get(i)).calculaMedia() == 1) {
                sit = "Dependente";
              } else {
                sit = "Aprovado";
              }
              saida += lista.get(i).toString() + "\nSituação: " + sit + "\n\n";
            }
          }
          JTextArea text = new JTextArea(saida);
          JScrollPane scroll = new JScrollPane(text);
          scroll.setPreferredSize(new java.awt.Dimension(300, 180));
          JOptionPane.showMessageDialog(null, scroll, "Exibindo Alunos", JOptionPane.PLAIN_MESSAGE);
        }
      } else if(e.getSource() == rDependente) {
        if(lista.isEmpty()) {
          JOptionPane.showMessageDialog(null, "Não há um aluno dependente na lista.", "ATENÇÃO", JOptionPane.PLAIN_MESSAGE);
        } else {
          String saida = "", sit = "";
          for(int i = 0; i < lista.size(); i++) {
            if(lista.get(i) instanceof Dependente) {
              if(((Dependente) lista.get(i)).calculaMedia() == 0) {
                sit = "Reprovado";
              } else if(((Dependente) lista.get(i)).calculaMedia() == 1) {
                sit = "Dependente";
              } else {
                sit = "Aprovado";
              }

              saida += lista.get(i).toString() + "\nSituacão: " + sit + "\n\n";
            }
          }
          JTextArea text = new JTextArea(saida);
          JScrollPane scroll = new JScrollPane(text);
          scroll.setPreferredSize(new java.awt.Dimension(300, 180));
          JOptionPane.showMessageDialog(null, scroll, "Exibindo Alunos Dependentes", JOptionPane.PLAIN_MESSAGE);
        }
      }
    }
  }

  public static void main(String[] args) {
    App a = new App();
    a.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    a.pack();
    a.setLocationRelativeTo(null);
    a.setVisible(true);
  }
}