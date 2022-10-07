/*

	Projeto de extensão - Robótica educacional
	Escopo algoritmo - Robô seguidor de linha
*/

#define sensorDir A1
#define sensorEsq A0
#define INTERVALO 200
#define ANDANDO 100
#define PARADO 0

int motorDir = 5;
int motorEsq = 6;
int ESQUERDA;
int DIREITA;


void setup() {

  Serial.begin(9600);
  pinMode(motorDir, OUTPUT);
  pinMode(motorEsq, OUTPUT);
  analogWrite(motorDir, ANDANDO);
  analogWrite(motorEsq, ANDANDO);

}

void loop() {

	ESQUERDA = analogRead(sensorEsq); // Leitura do sensor infravermelho esquerdo
  DIREITA = analogRead(sensorDir); // Leitura do sensor infravermelho direito

  if(ESQUERDA < INTERVALO && DIREITA < INTERVALO) {
    Frente();
  }
  if(DIREITA > 200) {
    Horario();
    while(true) {
      ESQUERDA = analogRead(sensorEsq);
      if(ESQUERDA > 200)
        break;
    }
  }
  if(ESQUERDA > 200) {
    Antiorario();
    while(true) {
      DIREITA = analogRead(sensorDir);
      if(DIREITA > 200)
        break;
    }
  }
}


//Robô caminha para frente
void Frente() {
  analogWrite(motorDir, ANDANDO);
  analogWrite(motorEsq, ANDANDO);
}

//Robô gira no sentido anti-horario
void Antihorario() {
  analogWrite(motorDir, ANDANDO);
  analogWrite(motorEsq, PARADO);
}

//Robô gira no sentido horário
void Horario() {
  analogWrite(motorDir, PARADO);
  analogWrite(motorEsq, ANDANDO);
}

//Robô permanece em repouso
void Parar() {
  analogWrite(motorDir, PARADO);
  analogWrite(motorEsq, PARADO);
}
