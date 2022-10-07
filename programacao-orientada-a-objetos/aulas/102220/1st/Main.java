import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

import java.util.ArrayList;

import src.components.Field;
import src.elements.Assalariado;
import src.elements.Comissionado;
import src.elements.ComissionadoAssalariado;
import src.elements.Empregado;
import src.elements.Horista;

public class Main extends JFrame implements ActionListener, ItemListener {
  private static final long serialVersionUID = 4648172894076113183L;

  private ArrayList<Empregado> lista = new ArrayList<Empregado>();
  
  private ButtonGroup bg;
  private Field nome, departamento, salarioAssalariado, descontosAssalariado, vendasComissionado, comissaoComissionado, bonusComissionado, salarioComissionado, horasHorista, salarioHorista;
  private JButton adicionar, exibir, exibirAssalariado, exibirComissionado, exibirComissionadoAssalariado, exibirHorista;
  private JPanel painelAssalariado, painelComissionado, painelComissionadoAssalariado, painelGeral, painelHorista;
  private JRadioButton assalariado, comissionado, comissionadoAssalariado, horista;

  public Main() {
    // Título da janela
    super("FIRMA");
    
    // Layout global
    setLayout(new BorderLayout());
    
    // Painel Norte
    assalariado = new JRadioButton("Assalariado", true);
    comissionado = new JRadioButton("Comissionado", false);
    comissionadoAssalariado = new JRadioButton("Comissionado Assalariado", false);
    horista = new JRadioButton("Horista", false);
    
    assalariado.addItemListener(this);
    comissionado.addItemListener(this);
    comissionadoAssalariado.addItemListener(this);
    horista.addItemListener(this);

    bg = new ButtonGroup();
    bg.add(assalariado);
    bg.add(comissionado);
    bg.add(comissionadoAssalariado);
    bg.add(horista);

    JPanel Norte = new JPanel(new FlowLayout());
    Norte.add(assalariado);
    Norte.add(comissionado);
    Norte.add(comissionadoAssalariado);
    Norte.add(horista);
    // Fim Painel Norte

    // Criar campos gerais
    nome = new Field("Nome", 10);
    departamento = new Field("Departamento", 10);
    // Fim Criar campos gerais

    // Painel Geral
    painelGeral = new JPanel();
    painelGeral.setLayout(new BoxLayout(painelGeral, BoxLayout.Y_AXIS));
    painelGeral.add(nome);
    painelGeral.add(departamento);
    // Fim Painel Geral

    // Criar campos Assalariado
    salarioAssalariado = new Field("Salário", 10);
    descontosAssalariado = new Field("Desconto", 10);
    // Fim Criar campos Assalariado

    // Painel Assalariado
    painelAssalariado = new JPanel();
    painelAssalariado.setLayout(new BoxLayout(painelAssalariado, BoxLayout.Y_AXIS));
    painelAssalariado.add(salarioAssalariado);
    painelAssalariado.add(descontosAssalariado);
    // Fim Painel Assalariado

    // Criar campos Comissionado
    vendasComissionado = new Field("Total de Vendas", 10);
    comissaoComissionado = new Field("Taxa de Comissão", 10);
    bonusComissionado = new Field("Bonus", 10);
    // Fim Criar campos Comissionado

    // Painel Comissionado
    painelComissionado = new JPanel();
    painelComissionado.setLayout(new BoxLayout(painelComissionado, BoxLayout.Y_AXIS));
    painelComissionado.add(vendasComissionado);
    painelComissionado.add(comissaoComissionado);
    painelComissionado.add(bonusComissionado);
    // Fim Painel Comissionado

    // Criar campos Comissionado Assalariado
    vendasComissionado = new Field("Total de Vendas", 10);
    comissaoComissionado = new Field("Taxa de Comissão", 10);
    bonusComissionado = new Field("Bonus", 10);
    salarioComissionado = new Field("Salário Base", 10);
    // Fim Criar campos Comissionado Assalariado

    // Painel Comissionado Assalariado
    painelComissionadoAssalariado = new JPanel();
    painelComissionadoAssalariado.setLayout(new BoxLayout(painelComissionadoAssalariado, BoxLayout.Y_AXIS));
    painelComissionadoAssalariado.add(vendasComissionado);
    painelComissionadoAssalariado.add(comissaoComissionado);
    painelComissionadoAssalariado.add(bonusComissionado);
    painelComissionadoAssalariado.add(salarioComissionado);
    // Fim Painel Comissionado Assalariado
    
    // Criar campos Horista
    horasHorista = new Field("Horas Trabalhadas", 10);
    salarioHorista = new Field("Salário/hora", 10);
    // Fim Criar campos Horista

    // Painel Horista
    painelHorista = new JPanel();
    painelHorista.setLayout(new BoxLayout(painelHorista, BoxLayout.Y_AXIS));
    painelHorista.add(horasHorista);
    painelHorista.add(salarioHorista);
    // Fim Painel Horista

    // Padrão de visibilidade dos Painéis
    painelGeral.setVisible(true);
    painelAssalariado.setVisible(true);
    painelComissionado.setVisible(false);
    painelComissionadoAssalariado.setVisible(false);
    painelHorista.setVisible(false);
    // Fim Padrão de visibilidade dos Painéis

    // Cria painel central
    JPanel Centro = new JPanel();
    Centro.setLayout(new BoxLayout(Centro, BoxLayout.Y_AXIS));
    Centro.add(painelGeral);
    Centro.add(painelAssalariado);
    Centro.add(painelComissionado);
    Centro.add(painelComissionadoAssalariado);
    Centro.add(painelHorista);

    Centro.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
    // Fim painel central

    // Botões Sul
    adicionar = new JButton("Adicionar Funcionário");
    exibir = new JButton("Exibir Todos");
    exibirAssalariado = new JButton("Exibir Assalariados");
    exibirComissionado = new JButton("Exibir Comissionados");
    exibirComissionadoAssalariado = new JButton("Exibir Comissionados Assalariados");
    exibirHorista = new JButton("Exibir Horistas");
    // Fim Botões Sul

    // Painel Sul
    JPanel Sul = new JPanel();
    Sul.setLayout(new BoxLayout(Sul, BoxLayout.Y_AXIS));

    JPanel Aux = new JPanel(new FlowLayout());
    JPanel Aux1 = new JPanel(new FlowLayout());

    Aux.add(adicionar);
    Aux.add(exibir);
    Aux.add(exibirAssalariado);

    Aux1.add(exibirComissionado);
    Aux1.add(exibirComissionadoAssalariado);
    Aux1.add(exibirHorista);

    Sul.add(Aux);
    Sul.add(Aux1);
    // Fim Painel Sul

    // Adiciona Funções aos Botões
    adicionar.addActionListener(this);
    exibir.addActionListener(this);
    exibirAssalariado.addActionListener(this);
    exibirComissionado.addActionListener(this);
    exibirComissionadoAssalariado.addActionListener(this);
    exibirHorista.addActionListener(this);
    // Fim Adiciona Funções aos Botões

    // Adiciona painéis à tela
    add(Norte, BorderLayout.NORTH);
    add(Centro, BorderLayout.CENTER);
    add(Sul, BorderLayout.SOUTH);
  }

  public static void main(String[] args) {
    Main x = new Main();
    x.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
    x.pack();
    x.setLocationRelativeTo(null);
    x.setVisible(true);    
  }

  @Override
  public void itemStateChanged(ItemEvent e) {
    if(e.getSource() == assalariado) {
      painelAssalariado.setVisible(true);
      painelComissionado.setVisible(false);
      painelComissionadoAssalariado.setVisible(false);
      painelHorista.setVisible(false);
    } else if(e.getSource() == comissionado) {
      painelAssalariado.setVisible(false);
      painelComissionado.setVisible(true);
      painelComissionadoAssalariado.setVisible(false);
      painelHorista.setVisible(false);
    } else if(e.getSource() == comissionadoAssalariado) {
      painelAssalariado.setVisible(false);
      painelComissionado.setVisible(false);
      painelComissionadoAssalariado.setVisible(true);
      painelHorista.setVisible(false);
    } else if(e.getSource() == horista) {
      painelAssalariado.setVisible(false);
      painelComissionado.setVisible(false);
      painelComissionadoAssalariado.setVisible(false);
      painelHorista.setVisible(true);
    }
    this.pack();
  }

  @Override
  public void actionPerformed(ActionEvent e) {
    String s = "", title = "";
    if(e.getSource() == adicionar) {
      String n = nome.getValue(), d = departamento.getValue();
      if(assalariado.isSelected()) {
        Double salario, desconto;
        String sal = salarioAssalariado.getValue(), desc = descontosAssalariado.getValue();
        title = "Sucesso";
        try {
          salario = Double.parseDouble(sal);
          try {
            desconto = Double.parseDouble(desc);
            Assalariado a = new Assalariado(n, d, salario, desconto);
            lista.add(a);
            JOptionPane.showMessageDialog(null, "Inserido com sucesso!", title, JOptionPane.INFORMATION_MESSAGE);
          } catch(NumberFormatException err) {
            title = "Erro";
            JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
          }
        } catch(NumberFormatException err) {
          title = "Erro";
          JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
        }
      } else if(comissionado.isSelected()) {
        String v = vendasComissionado.getValue(), c = comissaoComissionado.getValue(), b = bonusComissionado.getValue();
        Double vendas, comissao, bonus;
        try {
          vendas = Double.parseDouble(v);
          try {
            comissao = Double.parseDouble(c);
            try {
              bonus = Double.parseDouble(b);
              if(comissionadoAssalariado.isSelected()) {
                String sal = salarioComissionado.getValue();
                Double salario;
                try {
                  salario = Double.parseDouble(sal);
                  ComissionadoAssalariado ca = new ComissionadoAssalariado(n, d, vendas, comissao, bonus, salario);
                  lista.add(ca);
                  JOptionPane.showMessageDialog(null, "Inserido com sucesso!", title, JOptionPane.INFORMATION_MESSAGE);
                } catch(NumberFormatException err) {
                  title = "Erro";
                  JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
                }
              } else {
                Comissionado com = new Comissionado(n, d, vendas, comissao, bonus);
                lista.add(com);
                JOptionPane.showMessageDialog(null, "Inserido com sucesso!", title, JOptionPane.INFORMATION_MESSAGE);
              }
            } catch(NumberFormatException err) {
              title = "Erro";
              JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
            }
          } catch(NumberFormatException err) {
            title = "Erro";
            JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
          }
        } catch(NumberFormatException err) {
          title = "Erro";
          JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
        }
      } else if(horista.isSelected()) {
        String h = horasHorista.getValue(), sh = salarioHorista.getValue();
        Double salario;
        Integer horas;
        try {
          horas = Integer.parseInt(h);
          try {
            salario = Double.parseDouble(sh);
            Horista ho = new Horista(n, d, horas, salario);
            lista.add(ho);
            JOptionPane.showMessageDialog(null, "Inserido com sucesso!", title, JOptionPane.INFORMATION_MESSAGE);
          } catch(NumberFormatException err) {
            title = "Erro";
            JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
          }
        } catch(NumberFormatException err) {
          title = "Erro";
          JOptionPane.showMessageDialog(null, err.getStackTrace(), title, JOptionPane.ERROR_MESSAGE);
        }
      }
    } else if(e.getSource() == exibir) {
      for(int i = 0; i < lista.size(); i++)
        s += lista.get(i).toString();
      title = "Todos os Registros";
    } else if(e.getSource() == exibirAssalariado) {
      for(int i = 0; i < lista.size(); i++)
        if(lista.get(i) instanceof Assalariado)
          s += lista.get(i).toString();
      title = "Todos os Registros (Assalariado)";
    } else if(e.getSource() == exibirComissionado) {
      for(int i = 0; i < lista.size(); i++)
        if(lista.get(i) instanceof Comissionado)
          s += lista.get(i).toString();
      title = "Todos os Registros (Comissionado)";
    } else if(e.getSource() == exibirComissionadoAssalariado) {
      for(int i = 0; i < lista.size(); i++)
        if(lista.get(i) instanceof ComissionadoAssalariado)
          s += lista.get(i).toString();
      title = "Todos os Registros (Comissionado Assalariado)";
    } else if(e.getSource() == exibirHorista) {
      for(int i = 0; i < lista.size(); i++)
        if(lista.get(i) instanceof Horista)
          s += lista.get(i).toString();
      title = "Todos os Registros (Horista)";
    }

    if(e.getSource() == exibir || e.getSource() == exibirAssalariado || e.getSource() == exibirComissionado
        || e.getSource() == exibirComissionadoAssalariado || e.getSource() == exibirHorista)
      if(lista.isEmpty())
          s = "A lista está vazia";
      JOptionPane.showMessageDialog(null, s, title, JOptionPane.PLAIN_MESSAGE);
  }
}