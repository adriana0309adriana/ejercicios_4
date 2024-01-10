const int potPin = A0;  // Pin analógico conectado al potenciómetro
const int ledPins[] = {9, 10, 11};  // Pines digitales conectados a los LEDs
int potValue;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  // Lectura del valor del potenciómetro
  potValue = analogRead(potPin);

  // Secuencia #1: Encender LEDs de izquierda a derecha
  if (potValue >= 0 && potValue <= 500) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(1000);
    }
  }

  // Secuencia #2: Encender un LED a la vez de derecha a izquierda
  else if (potValue > 500 && potValue <= 1000) {
    for (int i = 2; i >= 0; i--) {
      digitalWrite(ledPins[i], HIGH);
      delay(1000);
    }
  }

  // Apagar todos los LEDs al final de cada secuencia
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}
