package components.tabs.pagamento.paineis;

import java.util.Vector;

import javax.swing.BoxLayout;
import javax.swing.JComponent;

import components.Campo;
import components.CampoBox;

public class PainelCartao extends JComponent {
  private static final long serialVersionUID = 1L;
  private Campo ncartao;
  private CampoBox operadora;
  
  public PainelCartao() {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    ncartao = new Campo("Nº do Cartão");
    Vector<String> op = new Vector<String>();
    op.add("Banco do Brasil");
    op.add("Bradesco");
    op.add("Caixa Econômica");
    op.add("Cetelem");
    op.add("Santander");
    operadora = new CampoBox("Operadora", op);

    add(ncartao);
    add(operadora);
  }

  public String getNCartao() {
    return ncartao.getText();
  }

  public String getOperadora() {
    return operadora.getSelected().toString();
  }

  public void limparTexto() {
    ncartao.cleanText();
  }
}
