import java.util.Stack;
import java.util.Collections;

/**
 * Classe Baralho
 */
public class BaralhoStack
{
    private Stack<Carta> baralho = new Stack<Carta>();
    private Stack<Carta> morto = new Stack<Carta>();

	/**
	 * Construtor
	 */
    public BaralhoStack()
    {
        Carta c;
        char naipe = 'o';
        int numCarta;
        String nome;

        for(int i = 0; i < 4; i++)
        {
            switch(i)
            {
                case 0:
                {
                    naipe = 'o';
                break;
                }
                case 1:
                {
                    naipe = 'e';
                break;
                }
                case 2:
                {
                    naipe = 'c';
                break;
                }
                case 3:
                {
                    naipe = 'p';
                break;
                }
            }// Switch i

            for(numCarta = 1; numCarta <= 13; numCarta++)
            {
                nome = String.format("%d-%c.png", numCarta, naipe);
                c = new Carta(nome, numCarta, naipe);
                baralho.push(c);
            }// for numCarta
        }// for naipe
    }// Construtor


	/**
	 * setBaralho
	 * @param x
	 */
    public void setBaralho(Stack<Carta> x)
    {
        this.baralho = x;
    }

	/**
	 * zeraBaralho
	 */
    public void zeraBaralho()
    {
        baralho.clear();
    }

	/**
	 * adiciona
	 * @param c
	 */
    public void adiciona(Carta c)
    {
        baralho.push(c);
    }

	/**
	 * embaralha
	 */
    public void embaralha()
    {
        Collections.shuffle(baralho);
    }

	/**
	 * qtdCartas
	 * @return
	 */
    public int qtdCartas()
    {
        return baralho.size();
    }

	/**
	 * getCarta
	 * @param pos
	 * @return
	 */
	public Carta getCarta()
	{
		Carta c = baralho.pop();
        morto.push(c);
		return c;
	}

	/**
	 * toString
	 */
	public String toString()
	{
		String frase = "";
		for(Carta c:baralho)
			frase += c.toString();
        if(baralho.size() == 0)
            frase = "Não há cartas";
		return frase;
    }

    public String exibeMorto()
    {
        String frase = "";
        for(Carta c:morto)
            frase += c.toString();
        if(morto.size() == 0)
            frase = "Não há cartas";
        return frase;
    }
}