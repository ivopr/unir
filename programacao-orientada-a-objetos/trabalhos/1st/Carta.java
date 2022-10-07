/**
 * Class carta
 * Refere a cada carta do Baralho
 */
public class Carta
{
    private String img;
    private int num;
    private char np;

    /**
     * Construtor nulo
     */
    public Carta()
    {
        this.img = "1-0.png";
        this.num = 0;
        this.np = 'o';
    }

    /**
     * Construtor não nulo
     * @param image
     * @param numero
     * @param naipe
     */
    public Carta(String image, int numero, char naipe)
    {
        this.img = image;
        this.num = numero;
        this.np = naipe;
    }

    /**
     * Set imagem
     * @param image
     */
    public void setImage(String image)
    {
        this.img = image;
    }

    /**
     * Set numero
     * @param numero
     */
    public void setNumero(int numero)
    {
        this.num = numero;
    }

    /**
     * Set naipe
     * @param naipe
     */
    public void setNaipe(char naipe)
    {
        this.np = naipe;
    }

    /**
     * Get imagem
     * @return
     */
    public String getImage()
    {
        return this.img;
    }

    /**
     * Get numero
     * @return
     */
    public int getNumero()
    {
        return this.num;
    }

    /**
     * Get naipe
     * @return
     */
    public char getNaipe()
    {
        return this.np;
    }

    /**
     * toString
     */
    public String toString()
    {
        String frase = "";

        switch(this.np)
        {
            case 'o':
            {
                frase = "Ouro - ";
            break;
            }
            case 'e':
            {
                frase = "Espada - ";
            break;
            }
            case 'c':
            {
                frase = "Copas - ";
            break;
            }
            case 'p':
            {
                frase = "Paus - ";
            break;
            }
            default: 
            {
                frase = "Nulo - ";
            break;
            }
        }// Switch Naipe Cartas

        switch(this.num)
        {
            case 1:
            {
                frase += "Ás\n";
            break;
            }
            case 11:
            {
                frase += "Valete\n";
            break;
            }
            case 12:
            {
                frase += "Dama\n";
            break;
            }
            case 13:
            {
                frase += "Rei\n";
            break;
            }
            default:
            {
                frase += "Nro. " + String.format("%d\n", this.num);
            break;
            }
        }// Switch Número Cartas
        return frase;
    }// toString
}