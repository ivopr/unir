import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import javax.swing.JOptionPane;

/**
 * @author haganezuka
 *
 */
public class Vetor {

	Random rd = new Random();
	List<Integer> vetor;
	boolean ordenado;
	int ponteiro, MAX;
	
	/**
	 * construtor
	 */
	public Vetor() {
		MAX = 100;
		ordenado = false;
		ponteiro = -1;
		vetor = new ArrayList<Integer>();
	}
	
	/**
	 * gerador
	 */
	public void gerar() {
		int n, i;
		for(i = 0; i < MAX; i++) {
			n = rd.nextInt(999);
			vetor.add(n);
		}
	}
	
	/**
	 * busca um n�mero no vetor
	 * @param num
	 * @return
	 */
	public int buscaExaustiva(int num) {
		for(ponteiro = 0; ponteiro < vetor.size(); ponteiro++) {
			if(num == vetor.get(ponteiro))
				return ponteiro;
		}
		return -1;
	}
	
	/**
	 * sobrescreve a fun��o toString
	 */
	public String toString() {
		String saida = "";
		for(int i = 0; i < vetor.size() / 4; i++) {
			saida += String.format("[%03d] = %03d    |    [%03d] = %03d    |    [%03d] = %03d    |    [%03d] = %03d\n",
						i, vetor.get(i),
						i + 25, vetor.get(i + 25),
						i + 50, vetor.get(i + 50),
						i + 75, vetor.get(i + 75)
					);
		}
		return saida;
	}
	
	/**
	 * ordena o vetor
	 */
	public void ordena() {
		Collections.sort(vetor);
		ordenado = true;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String menu;
		char m;
		Vetor v = new Vetor();
		do {
			menu = JOptionPane.showInputDialog(
					"-=[MENU]=-\n" + 
					"1 - Gerar vetor\n" + 
					"2 - Exibir\n" + 
					"3 - Busca\n" + 
					"4 - Ordenar\n" + 
					"0 - Sair");
			menu = menu.toUpperCase();
			m = menu.charAt(0);
			switch(m) {
				case '1':{
					v.gerar();
				break;
				}
				
				case '2': {
					String saida = v.toString();
					JOptionPane.showMessageDialog(null, saida);
				break;
				}
				
				case '3': {
					String txt = JOptionPane.showInputDialog("Entre com um número: ");
					int num = Integer.parseInt(txt);
					int posicao = v.buscaExaustiva(num);
					if(posicao == -1) {
						JOptionPane.showMessageDialog(null, "Número não encontrado.");
					} else {
						String encontrou = String.format("Número encontrado na posição %d", posicao);
						JOptionPane.showMessageDialog(null, encontrou);
					}
				break;
				}
				
				case '4': {
					v.ordena();
				break;
				}
				
				case '0': {
					System.exit(0);
				break;
				}
			}
		} while(m != 0);
	}
}
