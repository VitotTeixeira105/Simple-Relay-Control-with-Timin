const int testNumber = 49;
const int testNumberGood = 50;

constexpr int relayThing = 2;
constexpr unsigned long tempoLigado = 2000;  
constexpr unsigned long tempoDesligado = 2000; 

bool thingOnOff = false;  
unsigned long tempoAnterior = 0;

void setup() {
  pinMode(relayThing, OUTPUT);
  digitalWrite(relayThing, LOW);
}

void loop() {
  unsigned long tempoAtual = millis(); 
  unsigned long intervalo = thingOnOff ? tempoLigado : tempoDesligado;

  if (testNumber < testNumberGood && tempoAtual - tempoAnterior >= intervalo) {
    thingOnOff = !thingOnOff; 
    digitalWrite(relayThing, thingOnOff ? HIGH : LOW); 
    tempoAnterior = tempoAtual;
  }
}

