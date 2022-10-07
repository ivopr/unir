package src.components;

import java.awt.GridLayout;

import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Field extends JComponent {
  private static final long serialVersionUID = 1L;
  private JLabel label;
  private JTextField textField;

  public Field(String tlabel, int tSize) {
    setLayout(new GridLayout(1, 2));
    label = new JLabel(tlabel);
    textField = new JTextField(tSize);
    add(label);
    add(textField);
  }

  public String getValue() {
    return this.textField.getText();
  }

  public void resetValue() {
    this.textField.setText("");
  }
}
