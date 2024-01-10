const int buttonLeftPin = 2;  // Pin del botón izquierdo
const int buttonRightPin = 3; // Pin del botón derecho
const int ledPins[] = {7, 6, 5, 4, 8};  // Pines digitales conectados a los LEDs
int currentLed = 2;  // Inicial con el led #3 encendido
int blinkCount = 0;  // Contador para el parpadeo

void setup() {
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }

  pinMode(buttonLeftPin, INPUT_PULLUP);
  pinMode(buttonRightPin, INPUT_PULLUP);

  digitalWrite(ledPins[currentLed], HIGH);  // Enciende el led inicial
}

void loop() {
  if (digitalRead(buttonLeftPin) == LOW) {
    changeLed(-1);  // Mueve el led a la izquierda
    blink(3);       // Parpadea 3 veces
  }

  if (digitalRead(buttonRightPin) == LOW) {
    changeLed(1);   // Mueve el led a la derecha
    blink(3);       // Parpadea 3 veces
  }
}

void changeLed(int direction) {
  digitalWrite(ledPins[currentLed], LOW);  // Apaga el led actual

  currentLed += direction;  // Cambia la posición del led

  // Verifica si alcanzó un extremo y ajusta la posición
  if (currentLed < 0) {
    currentLed = 4;
    blink(4);  // Parpadea todos los leds 4 veces
  } else if (currentLed > 4) {
    currentLed = 0;
    blink(4);  // Parpadea todos los leds 4 veces
  }

  digitalWrite(ledPins[currentLed], HIGH);  // Enciende el nuevo led
}

void blink(int times) {
  for (int i = 0; i < times; i++) {
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], HIGH);
    }
    delay(500);
    for (int j = 0; j < 5; j++) {
      digitalWrite(ledPins[j], LOW);
    }
    delay(500);
  }
}
