package components;

import java.awt.Dimension;
import java.awt.GridLayout;

import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

public class Campo extends JComponent {
  private static final long serialVersionUID = 1L;
  private GridLayout layout = new GridLayout(1, 2);
  private JTextField ftf = new JTextField(10);

  public Campo(String l) {
    JLabel label = new JLabel(l);
    ftf.setHorizontalAlignment(JTextField.CENTER);
    setBorder(new EmptyBorder(1, 5, 1, 5));
    setMaximumSize(new Dimension(384, 24));
    setLayout(layout);
    add(label);
    add(ftf);
  }

  public String getText() {
    return this.ftf.getText();
  }

  public void cleanText() {
    this.ftf.setText("");
  }
}
