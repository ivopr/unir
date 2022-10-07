/*
  estrutura de dados I
  lista 4 - ex 4
  aluno: ivo vieira
  compilador: TDM-GCC
  sistema operacional: windows

  esse eu tomei a liberdade de mudar pra c++ desculpa professora
*/
#include <azrael.h>

using namespace std;

int main()
{
  int tams, num_vogal = 0;
  char *frase, *pont;

  cout << "entre com o tamanho maximo da frase: ";
  cin >> tams;

  frase = static_cast<char*>(malloc(tams * sizeof(char)));

  if(frase == NULL)
  {
    cout << "nao foi possivel alocar o espaco necessario" << endl;
    exit(0);
  }

  cout << "entre com a frase: ";
  cin.ignore();
  cin.getline(frase, tams);

  pont = frase;
  while(*pont)
  {
    if(*pont == 'a' || *pont == 'e' || *pont == 'i' || *pont == 'o' || *pont == 'u')
    {
      num_vogal++;
    }
    pont++;
  }
  cout << "a frase tem " << num_vogal << " vogais, " << strlen(frase) << " caracteres e " << tams - strlen(frase) << " espacos em branco" << endl;
  return 0;
}