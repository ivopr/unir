import java.awt.*;
import java.awt.event.*;
import java.util.List;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.border.*;

public class Main extends JFrame implements ActionListener
{
    static final long serialVersionUID = 42L;
    JButton bInsere, bExibe;
    JLabel lNome, lData;
    JTextField tNome, tDia, tMes, tAno;
    List<Pessoa> lista = new ArrayList<Pessoa>();

    /**
     * Construtor
     */
    public Main()
    {
        super("Pessoas");
        setLayout(new BorderLayout());
        
        /**
         * Painel norte
         */
        JPanel n = new JPanel(new FlowLayout());
        lNome = new JLabel("Nome: ");
        tNome = new JTextField(20);
        n.add(lNome);
        n.add(tNome);
        add(n, BorderLayout.NORTH);

        /**
         * Painel central
         */
        Border b = BorderFactory.createEtchedBorder();
        Border b1 = BorderFactory.createTitledBorder(b, "Data de Nascimento");
        JPanel c = new JPanel(new FlowLayout());
        tDia = new JTextField(4);
        tMes = new JTextField(4);
        tAno = new JTextField(6);
        c.add(tDia);
        c.add(tMes);
        c.add(tAno);
        c.setBorder(b1);
        add(c, BorderLayout.CENTER);

        /**
         * Painel sul
         */
        JPanel s = new JPanel(new FlowLayout());
        bInsere = new JButton("Inserir");
        bExibe = new JButton("Exibir Lista");
        s.add(bInsere);
        s.add(bExibe);
        add(s, BorderLayout.SOUTH);

        /**
         * Action Listeners
         */
        bInsere.addActionListener(this);
        bExibe.addActionListener(this);
    }

    /**
     * 
     */
    public void actionPerformed(ActionEvent e)
    {
        if(e.getSource() == bInsere)
        {
            int dia, mes, ano;
            String nome = tNome.getText();
            try
            {
                dia = Integer.parseInt(tDia.getText());
                mes = Integer.parseInt(tMes.getText());
                ano = Integer.parseInt(tAno.getText());
            }
            catch(NumberFormatException err)
            {
                dia = mes = 1;
                ano = 1990;
            }

            Pessoa p = new Pessoa(nome, dia, mes, ano);
            p.verificaSigno();
            lista.add(p);
            tNome.setText("");
            tDia.setText("");
            tMes.setText("");
            tAno.setText("");
            JOptionPane.showMessageDialog(null, "Cadastrado com sucesso!");
        }
        else if(e.getSource() == bExibe)
        {
            String texto = "";
            for(Pessoa p:lista)
            {
                texto += String.format("%s\n", p.toString());
            }
            JOptionPane.showMessageDialog(null, texto);
        }
    }

    /**
     * 
     * @param args
     */
    public static void main(String[] args)
    {
        Main m = new Main();
        m.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        m.pack();
        m.setLocationRelativeTo(null);
        m.setVisible(true);
    }
}