package components.tabs.pagamento;

import java.util.Vector;

import javax.swing.BoxLayout;
import javax.swing.JComponent;
import javax.swing.JOptionPane;

import components.Campo;
import components.CampoBox;

public class Norte extends JComponent {
  private static final long serialVersionUID = 1L;
  private Campo data, valor;
  private CampoBox cliente;

  public Norte(Vector<String> clientes) {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    data = new Campo("Data");
    valor = new Campo("Valor");
    cliente = new CampoBox("Cliente", clientes);

    add(data);
    add(valor);
    add(cliente);
  }

  public String getData() {
    return data.getText();
  }

  public Double getValor() {
    Double v = -1.0;
    try {
      v = Double.parseDouble(valor.getText());
    } catch(Exception e) {
      JOptionPane.showMessageDialog(null, e.getCause(), "ERRO", JOptionPane.ERROR_MESSAGE);
    }
    return v;
  }

  public String getSelectedClient() {
    return cliente.getSelected().toString();
  }

  public void limparTexto() {
    data.cleanText();
    valor.cleanText();
  }
}
