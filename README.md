# Simple-Relay-Control-with-Timin
Este código controla um relé com temporização, alternando entre ligado e desligado em intervalos definidos. A mudança só ocorre se testNumber for menor que testNumberGood. Utiliza millis() para verificar o tempo decorrido e inverter o estado do relé. Ideal para controle simples de relés com base em tempo e condições.

## Detalhes
Este código implementa um controle simples de um relé utilizando temporização. Ele alterna o estado do relé entre ligado e desligado com intervalos de tempo predefinidos (tempoLigado e tempoDesligado).

A alternância só ocorre se a variável testNumber for menor que testNumberGood. O código utiliza a função millis() para medir o tempo decorrido desde o início da execução e verificar quando é necessário alternar o estado do relé.

Funcionamento:
Define os tempos de ligado e desligado do relé.
Configura o pino do relé como saída e inicia desligado.
No loop principal (loop()), verifica se o intervalo de tempo especificado já passou.
Caso a condição seja atendida, inverte o estado do relé e atualiza o tempo de referência.
Este código é útil para aplicações onde se deseja um controle simples de um relé com base em temporização e uma condição específica.

## Exemplos
### Lampada
//Temperaturas para teste
const int temperaturaAmbiente = 49;
const int temperautraIdeal = 50;

constexpr int relayLamp = 2;
constexpr unsigned long tempoLigado = 2000;  
constexpr unsigned long tempoDesligado = 2000; 

bool LampLigado = false;  
unsigned long tempoAnterior = 0;

void setup() {
  pinMode(relayLamp, OUTPUT);
  digitalWrite(relayLamp, LOW);
}

void loop() {
  unsigned long tempoAtual = millis(); 
  unsigned long intervalo = LampLigado ? tempoLigado : tempoDesligado;

  if (temperaturaAmbiente < temperaturaIdeal && tempoAtual - tempoAnterior >= intervalo) {
    LampLigado = !LampLigado; 
    digitalWrite(relayLamp, LampLigado ? HIGH : LOW); 
    tempoAnterior = tempoAtual;
  }
}

### Stepper Motor
#include <Stepper.h>

const int PASSOS = 512;

Stepper myStepper(PASSOS, 3,4,5,6);

constexpr unsigned long tempoLigado = 3000;
constexpr unsigned long tempoDesligado = 5000;

unsigned long tempoAnterior = 0;
bool emMovimento = false;

void setup() {
  myStepper.setSpeed(60);
}

void loop() {
  unsigned long tempoAtual = millis();
  unsigned long intervalo = emMovimento ? tempoLigado : tempoDesligado;

  if (tempoAtual - tempoAnterior >= intervalo) {
      emMovimento = !emMovimento;
      myStepper.step(2048);
      tempoAnterior = tempoAtual;
  }
}
