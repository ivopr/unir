package components.tabs.pagamento.paineis;

import java.util.Vector;

import javax.swing.BoxLayout;
import javax.swing.JComponent;

import components.Campo;
import components.CampoBox;

public class PainelCheque extends JComponent {
  private static final long serialVersionUID = 1L;
  private Campo ncheque;
  private CampoBox banco;

  public PainelCheque() {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    ncheque = new Campo("Nº do Cheque");
    Vector<String> b = new Vector<String>();
    b.add("Banco do Brasil");
    b.add("Bradesco");
    b.add("Caixa Econômica");
    b.add("Itaú");
    b.add("Santander");
    banco = new CampoBox("Banco", b);

    add(ncheque);
    add(banco);
  }

  public String getNCheque() {
    return ncheque.getText();
  }

  public String getBanco() {
    return banco.getSelected().toString();
  }

  public void limparTexto() {
    ncheque.cleanText();
  }
}
