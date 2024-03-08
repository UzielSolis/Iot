#define LED 12 
int contador = 0;
int estado = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, INPUT);
}

void loop() {
  estado = digitalRead(LED);
  
  if (estado == LOW) {
    contador=contador+1;
    Serial.println("Hay un obstaculo");
    while (estado == LOW) {
      estado = digitalRead(LED);
    }
  }
  else {
    contador=contador+1;
    Serial.println("no hay obstaculo");
    while (estado == HIGH) {
      estado = digitalRead(LED);
    }
  }
  Serial.println(contador);
  if (contador > 24) {
    contador = 0;
  }
}
