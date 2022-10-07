package components;

import java.awt.Dimension;
import java.awt.GridLayout;
import java.util.Vector;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JComboBox;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.border.EmptyBorder;

@SuppressWarnings("all")
public class CampoBox extends JComponent {
  private static final long serialVersionUID = 1L;
  private GridLayout layout = new GridLayout(1, 2);
  private JComboBox cbox = new JComboBox();
  private DefaultComboBoxModel model = new DefaultComboBoxModel();

  public CampoBox(String lbl, Vector<String> data) {
    JLabel label = new JLabel(lbl);
    model = new DefaultComboBoxModel(data);
    cbox = new JComboBox(model);
    setBorder(new EmptyBorder(1, 5, 1, 5));
    setMaximumSize(new Dimension(384, 24));
    setLayout(layout);
    add(label);
    add(cbox);
  }

  public Object getSelected() {
    return cbox.getSelectedItem();
  }
}
