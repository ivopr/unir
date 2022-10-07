import java.util.Calendar;

public class Pessoa 
{
    private String nome, signo;
    private int dia, mes, ano;

    public Pessoa()
    {
        this.nome = this.signo = "";
        this.dia = this.mes = this.ano = 0;
    }

    public Pessoa(String n, int d, int m, int a)
    {
        this.nome = n;
        this.dia = d;
        this.mes = m;
        this.ano = a;
        this.signo = "";
    }

    /**
     * Get
     */
    public String getNome()
    {
        return this.nome;
    }
    
    public String getSigno()
    {
        return this.signo;
    }

    public int getDia()
    {
        return this.dia;
    }
    
    public int getMes()
    {
        return this.mes;
    }   
    
    public int getAno()
    {
        return this.ano;
    }

    /**
     * Set
     */
    public void setNome(String n)
    {
        this.nome = n;
    }

    public void setSigno(String s)
    {
        this.signo = s;
    }
    
    public void setDia(int d)
    {
        this.dia = d;
    }
    
    public void setMes(int m)
    {
        this.mes = m;
    }
    
    public void setAno(int a)
    {
        this.ano = a;
    }

    /**
     * Retorna o nome, data de nascimento e o signo
     * @return String saida
     */
    @Override
    public String toString()
    {
        String saida = String.format("%s, %d/%d/%d, %s",
            this.nome, this.dia, this.mes, this.ano, this.signo);
        return saida;
    }

    /**
     * Calcula e retorna a idade de i=um individuo 
     * @return int idade
     */
    public int getIdade()
    {
        Calendar data = Calendar.getInstance();
        int diaAtual = data.get(Calendar.DAY_OF_MONTH);
        int mesAtual = data.get(Calendar.MONTH);
        int anoAtual = data.get(Calendar.YEAR);
        int idade;
        
        if(this.mes > mesAtual || (this.mes == mesAtual && this.dia > diaAtual))
            idade = anoAtual - this.ano - 1;
        else
            idade = anoAtual - this.ano;
        return idade;
    }

    /**
     * Seta o signo de um individuo
     */
    public void verificaSigno()
    {
        switch(this.mes)
        {
            case 1:
            {
                if(this.dia < 20)
                    this.signo = "Capricórnio";
                else
                    this.signo = "Aquário";
            break;
            }

            case 2:
            {
                if(this.dia < 20)
                    this.signo = "Aquário";
                else
                    this.signo = "Peixes";
            break;
            }

            case 3:
            {
                if(this.dia < 20)
                    this.signo = "Peixes";
                else
                    this.signo = "Áries";
            break;
            }

            case 4:
            {
                if(this.dia < 20)
                    this.signo = "Áries";
                else
                    this.signo = "Touro";
            break;
            }

            case 5:
            {
                if(this.dia < 20)
                    this.signo = "Touro";
                else
                    this.signo = "Gemeos";
            break;
            }

            case 6:
            {
                if(this.dia < 20)
                    this.signo = "Gemeos";
                else
                    this.signo = "Câncer";
            break;
            }

            case 7:
            {
                if(this.dia < 20)
                    this.signo = "Câncer";
                else
                    this.signo = "Leão";
            break;
            }

            case 8:
            {
                if(this.dia < 20)
                    this.signo = "Leão";
                else
                    this.signo = "Virgem";
            break;
            }

            case 9:
            {
                if(this.dia < 20)
                    this.signo = "Virgem";
                else
                    this.signo = "Libra";
            break;
            }

            case 10:
            {
                if(this.dia < 20)
                    this.signo = "Libra";
                else
                    this.signo = "Escorpião";
            break;
            }

            case 11:
            {
                if(this.dia < 20)
                    this.signo = "Escorpião";
                else
                    this.signo = "Sagitário";
            break;
            }

            case 12:
            {
                if(this.dia < 20)
                    this.signo = "Sagitário";
                else
                    this.signo = "Capricórnio";
            break;
            }
        }
    }
}