/**
 * Java Swing imports
 */
import javax.swing.JButton;  
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

/**
 * Java AWT imports
 */
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * Classe Calculadora
 */
public class Calculadora extends JFrame implements ActionListener
{
    static final long serialVersionUID = 42L;
    JButton bClear, bDif, bDiv, bMul, bSum;
    JLabel texto, texto1, texto2, campo2;
    JTextField campo, campo1;

    /**
     * Função actionPerformed
     * Realiza as operações da calculadora
     */
    public void actionPerformed(ActionEvent e)
    {
        float num, num1, res;
        try
        {
            num = Float.parseFloat(campo.getText());
            num1 = Float.parseFloat(campo1.getText());
        }
        catch(NumberFormatException err)
        {
            num = 0;
            num1 = 0;
        }
        if(e.getSource() == bSum)
        {
            res = num + num1;
            campo2.setText(String.format("%5.2f", res));
        }
        else if(e.getSource() == bDif)
        {
            res = num - num1;
            campo2.setText(String.format("%5.2f", res));
        }
        else if(e.getSource() == bDiv)
        {
            res = num / num1;
            campo2.setText(String.format("%5.2f", res));
        }
        else if(e.getSource() == bMul)
        {
            res = num * num1;
            campo2.setText(String.format("%5.2f", res));
        }
        else if(e.getSource() == bClear)
        {
            campo.setText("");
            campo1.setText("");
            campo2.setText("");
        }
    }
    /**
     * Fim actionPerformed
     */

    /**
     * Construtor
     */
    public Calculadora()
    {
        setLayout(new FlowLayout());
		bSum = new JButton("+");
		bDif = new JButton("-");
		bDiv = new JButton("/");
		bMul = new JButton("*");
		bClear = new JButton("Limpar");
        
        // Novo painel 5x1
        JPanel dir = new JPanel(new GridLayout(5, 1));
        
        // Adicionando itens no painel
		dir.add(bSum);
		dir.add(bDif);
		dir.add(bMul);
		dir.add(bDiv);
		dir.add(bClear);
        
        // Novo painel 3x2
        JPanel cen = new JPanel(new GridLayout(3, 2));
        
        // Caixas de titulo
		texto = new JLabel("Entre com o valor 1 ", SwingConstants.LEFT);
		texto1 = new JLabel("Entre com o valor 2 ", SwingConstants.LEFT);
        texto2 = new JLabel("Resultado: ", SwingConstants.LEFT);
        
        // Caixas de inserção
		campo = new JTextField(10);
		campo1 = new JTextField(10);
        campo2  = new JLabel("0.00");
        
        // Adicionando a primeira caixa de titulo e de inserção no painel
		cen.add(texto);
        cen.add(campo);

        // Adicionando a segunda caixa de titulo e de inserção no painel
		cen.add(texto1);
        cen.add(campo1);

        // Adicionando a terceira caixa de titulo e de inserção no painel
		cen.add(texto2);
        cen.add(campo2);
        
        // Adicionando o painel 3x2 na tela (painel central)
        add(cen);
                
        // Adicionando o painel na tela (painel direito)
        add(dir);
		
		// Algo deve acontecer ao clicar os botões
		bSum.addActionListener(this);
		bDif.addActionListener(this);
		bMul.addActionListener(this);
		bDiv.addActionListener(this);
		bClear.addActionListener(this);
    }
    /**
     * Fim Contrutor
     */

    /**
     * Função Main
     * @param args
     */
    public static void main(String[] args) {
		// Cria uma nova instancia da calculadora
        Calculadora c = new Calculadora(); 
        
        // Definindo o titulo da janela
        c.setTitle("Calculadora");

        // Define como encerrar o programa
        c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        // Define automaticamente o tamanho necessário para acomodar todos os itens que serão exibidos
        c.pack();
        
        // Criando a nova instancia no centro da tela (a da maquina)
        c.setLocationRelativeTo(null);
        
        // Tornando a nova instancia visivel
		c.setVisible(true);
    }
    /**
     * Fim Main
     */
}