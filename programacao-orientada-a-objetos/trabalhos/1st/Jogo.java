import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.border.*;

public class Jogo extends JFrame implements ActionListener
{
    static final long serialVersionUID = 42L;

	BaralhoArrayList ba;
	BaralhoLinkedList bl;
	BaralhoStack bs;
	BaralhoVector bv;
    Carta c;
	Icon iAberto, iFechado, iVazio;
	JButton baAberto, baFechado, blAberto, blFechado, bsAberto, bsFechado, bvAberto, bvFechado,
			baExibe, baExibeMorto, blExibe, blExibeMorto, bsExibe, bsExibeMorto, bvExibe, bvExibeMorto,
			bCriaBaralho, bEmbaralha, bZeraBaralho;
	JPanel p, ne, nee, ned, nd, nde, ndd, se, see, sed, sd, sde, sdd, s;
	JScrollPane scroll;
	JTextArea message;
	String baralhoCriar, baralhoEmbaralhar, baralhoFechado, baralhoMorto, baralhoZerar, bPanelInfo;

    /**
     * Construtor
     */
    public Jogo()
    {
		// icone, título e layout principal do aplicativo
		ImageIcon icon = new ImageIcon(getClass().getResource("images/icon.png"));
		setIconImage(icon.getImage());
		setLayout(new BorderLayout());
		setTitle("Baralhos");

		// textos dos botões (para evitar repetição de uma longa cadeia de caracteres)
		baralhoCriar = "Recomeçar TODOS";
		baralhoEmbaralhar = "Embaralhar TODOS";
		baralhoFechado = "Exibir Cartas Restantes";
		baralhoMorto = "Exibir Cartas Removidas";
		baralhoZerar = "Encerrar TODOS";
		bPanelInfo = "Essas ações afetam TODOS os baralhos >>";

		// icones dos botões de carta
		iFechado = new ImageIcon(getClass().getResource("images/fechado.png"));
		iVazio = new ImageIcon(getClass().getResource("images/fechado2.png"));

		// novo baralho
		ba = new BaralhoArrayList();
		ba.embaralha();
		bl = new BaralhoLinkedList();
		bl.embaralha();
		bs = new BaralhoStack();
		bs.embaralha();
		bv = new BaralhoVector();
		bv.embaralha();

		// container
		p = new JPanel(new GridLayout(2, 2));

			// GridBag Constraints
			GridBagConstraints gbc = new GridBagConstraints();
			gbc.gridwidth = GridBagConstraints.REMAINDER;
			gbc.fill = GridBagConstraints.HORIZONTAL;

			// borda principal
			Border b = BorderFactory.createEtchedBorder();
		
			// painel ArrayList
        	Border b1 = BorderFactory.createTitledBorder(b, "Baralho ArrayList");
			ne = new JPanel(new FlowLayout());
				nee = new JPanel(new FlowLayout());
					baFechado = new JButton(iFechado);
					baAberto = new JButton(iVazio);
				nee.add(baFechado);
				nee.add(baAberto);
			ne.add(nee);
				ned = new JPanel(new GridBagLayout());
					baExibe = new JButton(baralhoFechado);
					baExibeMorto = new JButton(baralhoMorto);
				ned.add(baExibe, gbc);
				ned.add(baExibeMorto, gbc);
			ne.add(ned);
			ne.setBorder(b1);
		p.add(ne);
		
			// painel LinkedList
        	Border b2 = BorderFactory.createTitledBorder(b, "Baralho LinkedList");
			nd = new JPanel(new FlowLayout());
				nde = new JPanel(new FlowLayout());
					blFechado = new JButton(iFechado);
					blAberto = new JButton(iVazio);
				nde.add(blFechado);
				nde.add(blAberto);
			nd.add(nde);
				ndd = new JPanel(new GridBagLayout());
					blExibe = new JButton(baralhoFechado);
					blExibeMorto = new JButton(baralhoMorto);
				ndd.add(blExibe, gbc);
				ndd.add(blExibeMorto, gbc);
			nd.add(ndd);
			nd.setBorder(b2);
		p.add(nd);

			// painel Stack
			Border b3 = BorderFactory.createTitledBorder(b, "Baralho Stack");
			se = new JPanel(new FlowLayout());
				see = new JPanel(new FlowLayout());
					bsFechado = new JButton(iFechado);
					bsAberto = new JButton(iVazio);
				see.add(bsFechado);
				see.add(bsAberto);
			se.add(see);
				sed = new JPanel(new GridBagLayout());
					bsExibe = new JButton(baralhoFechado);
					bsExibeMorto = new JButton(baralhoMorto);
				sed.add(bsExibe, gbc);
				sed.add(bsExibeMorto, gbc);
			se.add(sed);
			se.setBorder(b3);
		p.add(se);

			// painel Vector
        	Border b4 = BorderFactory.createTitledBorder(b, "Baralho Vector");
			sd = new JPanel(new FlowLayout());
				sde = new JPanel(new FlowLayout());
					bvFechado = new JButton(iFechado);
					bvAberto = new JButton(iVazio);
				sde.add(bvFechado);
				sde.add(bvAberto);
			sd.add(sde);
				sdd = new JPanel(new GridBagLayout());
					bvExibe = new JButton(baralhoFechado);
					bvExibeMorto = new JButton(baralhoMorto);
				sdd.add(bvExibe, gbc);
				sdd.add(bvExibeMorto, gbc);
			sd.add(sdd);
			sd.setBorder(b4);
		p.add(sd);

		// adicionando container ao programa
		add(p, BorderLayout.CENTER);

		// painel dos botões
		s = new JPanel(new FlowLayout());
		s.add(new JLabel(bPanelInfo));
		bCriaBaralho = new JButton(baralhoCriar);
		s.add(bCriaBaralho);
		bEmbaralha = new JButton(baralhoEmbaralhar);
		s.add(bEmbaralha);
		bZeraBaralho = new JButton(baralhoZerar);
		s.add(bZeraBaralho);
		add(s, BorderLayout.SOUTH);

		// os botões servem pra algo, certo?
		bCriaBaralho.addActionListener(this);
		bEmbaralha.addActionListener(this);
		baExibe.addActionListener(this);
		baExibeMorto.addActionListener(this);
		blExibe.addActionListener(this);
		blExibeMorto.addActionListener(this);
		bsExibe.addActionListener(this);
		bsExibeMorto.addActionListener(this);
		bvExibe.addActionListener(this);
		bvExibeMorto.addActionListener(this);
		baFechado.addActionListener(this);
		blFechado.addActionListener(this);
		bsFechado.addActionListener(this);
		bvFechado.addActionListener(this);
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
			ba.zeraBaralho();
			ba = new BaralhoArrayList();
			baFechado.setIcon(iFechado);
			baAberto.setIcon(iVazio);

			bl.zeraBaralho();
			bl = new BaralhoLinkedList();
			blFechado.setIcon(iFechado);
			blAberto.setIcon(iVazio);

			bs.zeraBaralho();
			bs = new BaralhoStack();
			bsFechado.setIcon(iFechado);
			bsAberto.setIcon(iVazio);

			bv.zeraBaralho();
			bv = new BaralhoVector();
			bvFechado.setIcon(iFechado);
			bvAberto.setIcon(iVazio);
		}

		// botão embaralhar
		if(e.getSource() == bEmbaralha)
		{
			ba.embaralha();
			bl.embaralha();
			bs.embaralha();
			bv.embaralha();
		}

		// botão exibir ArrayList
		if(e.getSource() == baExibe)
		{
			String saida = ba.toString();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoFechado, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Morto ArrayList
		if(e.getSource() == baExibeMorto)
		{
			String saida = ba.exibeMorto();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoMorto, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir LinkedList
		if(e.getSource() == blExibe)
		{
			String saida = bl.toString();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoFechado, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Morto LinkedList
		if(e.getSource() == blExibeMorto)
		{
			String saida = bl.exibeMorto();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoMorto, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Stack
		if(e.getSource() == bsExibe)
		{
			String saida = bs.toString();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoFechado, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Morto Stack
		if(e.getSource() == bsExibeMorto)
		{
			String saida = bs.exibeMorto();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoMorto, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Vector
		if(e.getSource() == bvExibe)
		{
			String saida = bv.toString();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoFechado, JOptionPane.PLAIN_MESSAGE);
		}

		// botão exibir Morto Vector
		if(e.getSource() == bvExibeMorto)
		{
			String saida = bv.exibeMorto();
			message = new JTextArea(saida);
			scroll = new JScrollPane(message);
			message.setEditable(false);
			message.setLineWrap(true);
			message.setWrapStyleWord(true);
			scroll.setPreferredSize(new Dimension(150, 300));
			JOptionPane.showMessageDialog(null, scroll, baralhoMorto, JOptionPane.PLAIN_MESSAGE);
		}
		
		// botão zerar baralho
		if(e.getSource() == bZeraBaralho)
		{
			ba.zeraBaralho();
			baFechado.setIcon(iVazio);
			baAberto.setIcon(iVazio);

			bl.zeraBaralho();
			blFechado.setIcon(iVazio);
			blAberto.setIcon(iVazio);

			bs.zeraBaralho();
			bsFechado.setIcon(iVazio);
			bsAberto.setIcon(iVazio);

			bv.zeraBaralho();
			bvFechado.setIcon(iVazio);
			bvAberto.setIcon(iVazio);
		}

		// botão fechado (puxar carta)
		if(e.getSource() == baFechado)
		{
			if(ba.qtdCartas() > 0)
			{
				c = ba.getCarta(0);
				if(ba.qtdCartas() == 0)
					baFechado.setIcon(iVazio);
				String imagem = c.getImage();
				iAberto = new ImageIcon(getClass().getResource("images/" + imagem));
				baAberto.setIcon(iAberto);
			}
		}

		// botão fechado (puxar carta)
		if(e.getSource() == blFechado)
		{
			if(bl.qtdCartas() > 0)
			{
				c = bl.getCarta(0);
				if(bl.qtdCartas() == 0)
					blFechado.setIcon(iVazio);
				String imagem = c.getImage();
				iAberto = new ImageIcon(getClass().getResource("images/" + imagem));
				blAberto.setIcon(iAberto);
			}
		}

		// botão fechado (puxar carta)
		if(e.getSource() == bsFechado)
		{
			if(bs.qtdCartas() > 0)
			{
				c = bs.getCarta();
				if(bs.qtdCartas() == 0)
					bsFechado.setIcon(iVazio);
				String imagem = c.getImage();
				iAberto = new ImageIcon(getClass().getResource("images/" + imagem));
				bsAberto.setIcon(iAberto);
			}
		}

		// botão fechado (puxar carta)
		if(e.getSource() == bvFechado)
		{
			if(bv.qtdCartas() > 0)
			{
				c = bv.getCarta(0);
				if(bv.qtdCartas() == 0)
					bvFechado.setIcon(iVazio);
				String imagem = c.getImage();
				iAberto = new ImageIcon(getClass().getResource("images/" + imagem));
				bvAberto.setIcon(iAberto);
			}
		}
    }

    /**
     * Main
     * @param args
     */
    public static void main(String[] args)
    {
		Jogo j = new Jogo();
		j.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		j.pack();
		j.setLocationRelativeTo(null);
		j.setVisible(true);
    }
}