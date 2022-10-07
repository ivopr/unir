import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Jogo extends JFrame implements ActionListener
{
    static final long serialVersionUID = 42L;

    Baralho b;
    Carta c;
	JButton bAberto, bCriaBaralho, bEmbaralha, bExibe, bFechado, bZeraBaralho;
	JPanel p;
	Icon iAberto, iFechado, iVazio;

    /**
     * Construtor
     */
    public Jogo()
    {
		setLayout(new BorderLayout());

		// icones
		iFechado = new ImageIcon(getClass().getResource("images/fechado.png"));
		iVazio = new ImageIcon(getClass().getResource("images/fechado2.png"));

		// botões
		bFechado = new JButton(iFechado);
		bAberto = new JButton(iVazio);

		// novo baralho
		b = new Baralho();

		// painel central
		p = new JPanel(new FlowLayout());
		p.add(bFechado);
		p.add(bAberto);
		add(p, BorderLayout.CENTER);

		// painel sul
		p = new JPanel(new FlowLayout());
		bCriaBaralho = new JButton("Criar Baralho");
		p.add(bCriaBaralho);
		bEmbaralha = new JButton("Emabalhar");
		p.add(bEmbaralha);
		bZeraBaralho = new JButton("Zerar TUDO");
		p.add(bZeraBaralho);
		bExibe = new JButton("Exibe");
		p.add(bExibe);
		add(p, BorderLayout.SOUTH);

		// os botões servem pra algo, certo?
		bCriaBaralho.addActionListener(this);
		bEmbaralha.addActionListener(this);
		bExibe.addActionListener(this);
		bFechado.addActionListener(this);
		bZeraBaralho.addActionListener(this);
    }

    /**
     * actionPerformed
     * @param e
     */
    public void actionPerformed(ActionEvent e)
    {
		// botão de criar baralho
		if(e.getSource() == bCriaBaralho)
		{
			b.zeraBaralho();
			b = new Baralho();
			bFechado.setIcon(iFechado);
			bAberto.setIcon(iVazio);
		}

		// botão embaralhar
		if(e.getSource() == bEmbaralha)
		{
			b.embaralha();
		}

		// botão exibir
		if(e.getSource() == bExibe)
		{
			String saida = b.toString();
			JOptionPane.showMessageDialog(null, saida);
		}

		// botão fechado (puxar carta)
		if(e.getSource() == bFechado)
		{
			if(b.qtdCartas() > 0)
			{
				c = b.getCarta(0);
				if(b.qtdCartas() == 0)
					bFechado.setIcon(iVazio);
				String imagem = c.getImage();
				iAberto = new ImageIcon(getClass().getResource("images/" + imagem));
				bAberto.setIcon(iAberto);
			}
		}

		// botão zerar baralho
		if(e.getSource() == bZeraBaralho)
		{
			b.zeraBaralho();
			bFechado.setIcon(iVazio);
			bAberto.setIcon(iVazio);
		}
    }

    /**
     * Main
     * @param args
     */
    public static void main(String[] args)
    {
		Jogo j = new Jogo();
		j.setTitle("Hearthstone");
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j.pack();
		j.setLocationRelativeTo(null);
		j.setVisible(true);
    }
}