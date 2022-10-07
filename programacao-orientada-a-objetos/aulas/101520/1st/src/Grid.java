package src;

import javax.swing.*;
import java.awt.*;

public class Grid extends JFrame {
    private static final long serialVersionUID = 1L;

    private JButton UM, DOIS, TRES, QUATRO, CINCO, SEIS;

    public Grid() {
        super("Janela GridLayout");

        setLayout(new GridLayout(3,2)); // TESTAR COM (2,3,5,5)
        UM = new JButton("UM");
        DOIS = new JButton("DOIS");
        TRES = new JButton("TRES");
        QUATRO = new JButton("QUATRO");
        CINCO = new JButton("CINCO");
        SEIS = new JButton("SEIS");

        add(UM);
        add(DOIS);
        add(TRES);
        add(QUATRO);
        add(CINCO);
        add(SEIS); 
    }
}
