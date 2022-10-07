package components.tabs.pagamento;

import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.FlowLayout;

import javax.swing.BoxLayout;
import javax.swing.ButtonGroup;
import javax.swing.JComponent;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JRadioButton;

import components.tabs.pagamento.paineis.PainelCartao;
import components.tabs.pagamento.paineis.PainelCheque;

public class Centro extends JComponent {
  private static final long serialVersionUID = 1L;
  private JRadioButton cartao = new JRadioButton("Cartão"),
                       cheque = new JRadioButton("Cheque"),
                       dinheiro = new JRadioButton("Dinheiro");
  private PainelCartao pCartao;
  private PainelCheque pCheque;
  private Integer selectedPayment = 1;

  public Centro() {
    setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
    
    ButtonGroup radiogroup = new ButtonGroup();
    cartao.setOpaque(false);
    cartao.setSelected(true);
    cheque.setOpaque(false);
    dinheiro.setOpaque(false);
    radiogroup.add(cartao);
    radiogroup.add(cheque);
    radiogroup.add(dinheiro);

    JPanel radios = new JPanel();
    radios.setLayout(new BoxLayout(radios, BoxLayout.X_AXIS));
    radios.setOpaque(false);
    radios.add(cartao);
    radios.add(cheque);
    radios.add(dinheiro);

    add(radios);

    pCartao = new PainelCartao();
    pCartao.setVisible(true);

    pCheque = new PainelCheque();
    pCheque.setVisible(false);

    JPanel pDinheiro = new JPanel(new FlowLayout());
    JLabel lDinheiro = new JLabel("Pago à vista no caixa.");
    pDinheiro.add(lDinheiro);
    pDinheiro.setVisible(false);
    pDinheiro.setOpaque(false);

    add(pCartao);
    add(pCheque);
    add(pDinheiro);

    cartao.addItemListener(new ItemListener() {
      @Override
      public void itemStateChanged(ItemEvent e) {
        pCartao.setVisible(true);
        pCheque.setVisible(false);
        pDinheiro.setVisible(false);
        selectedPayment = 1;
      }
    });

    cheque.addItemListener(new ItemListener() {
      @Override
      public void itemStateChanged(ItemEvent e) {
        pCartao.setVisible(false);
        pCheque.setVisible(true);
        pDinheiro.setVisible(false);
        selectedPayment = 2;
      }
    });

    dinheiro.addItemListener(new ItemListener() {
      @Override
      public void itemStateChanged(ItemEvent e) {
        pCartao.setVisible(false);
        pCheque.setVisible(false);
        pDinheiro.setVisible(true);
        selectedPayment = 3;
      }
    });
  }

  public Integer getSelectedPayment() {
    return selectedPayment;
  }

  public String[] getCartaoData() {
    String[] res = {
      pCartao.getNCartao(),
      pCartao.getOperadora(),
    };

    return res;
  }

  public String[] getChequeData() {
    String[] res = {
      pCheque.getNCheque(),
      pCheque.getBanco(),
    };

    return res;
  }

  public void limparTexto() {
    pCartao.limparTexto();
    pCheque.limparTexto();
  }
}
