package src;

import javax.swing.*;
import java.awt.*;

public class Flow extends JFrame {
    private static final long serialVersionUID = 1L;

    private JButton BotaoEsq;
    private JButton BotaoDir;
    private JButton BotaoCentro; 

    public Flow() {
        super("Janela FlowLayout");
        
        setLayout(new FlowLayout());
        BotaoEsq = new JButton("Esq"); add(BotaoEsq);
        BotaoCentro = new JButton("Centro"); add(BotaoCentro);
        BotaoDir = new JButton("Dir"); add(BotaoDir);
    }
}
