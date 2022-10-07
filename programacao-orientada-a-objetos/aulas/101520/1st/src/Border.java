package src;

import javax.swing.*;
import java.awt.*;

public class Border extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextField valor1, valor2, resultado;
    private JLabel label1, label2, label3;
    private JButton limpa;
    private JButton adicao, subtracao, multiplicacao, divisao;

    public Border() {
        super ("Janela Border");

        setLayout(new BorderLayout());
        valor1 = new JTextField(5);
        valor2 = new JTextField(5);
        resultado = new JTextField(5);

        label1 = new JLabel("Valor 1..:", SwingConstants.RIGHT);
        label2 = new JLabel("Valor 2..:", SwingConstants.RIGHT);
        label3 = new JLabel("Resultado:", SwingConstants.RIGHT);
        limpa = new JButton("Clear");
        adicao = new JButton("+");
        subtracao = new JButton("-");
        multiplicacao = new JButton("*");
        divisao = new JButton("/");
        
        JPanel centro = new JPanel(new GridLayout(3, 2));
        JPanel leste = new JPanel(new GridLayout(4, 1));
        
        centro.add(label1);
        centro.add(valor1);
        centro.add(label2);
        centro.add(valor2);
        centro.add(label3);
        centro.add(resultado);
        add(centro, BorderLayout.CENTER);

        leste.add(adicao);
        leste.add(subtracao);
        leste.add(multiplicacao);
        leste.add(divisao);
        add(leste, BorderLayout.EAST);

        add(limpa, BorderLayout.SOUTH); 
    }
}
