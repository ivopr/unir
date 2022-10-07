import javax.swing.JFrame;

import src.Border;
import src.Flow;
import src.Grid;

public class Main {
    public static void main(String[] args) {
        Flow f = new Flow();
        f.pack();
        f.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        f.setLocationRelativeTo(null);
        f.setVisible(true);

        Grid g = new Grid();
        g.pack();
        g.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        g.setLocationRelativeTo(null);
        g.setVisible(true);

        Border b = new Border();
        b.pack();
        b.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        b.setLocationRelativeTo(null);
        b.setVisible(true);
    }
}