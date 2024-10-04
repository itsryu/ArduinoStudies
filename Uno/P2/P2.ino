#define TRIGGER_PIN 10
#define ECHO_PIN 9
#define GREEN_LED 13
#define YELLOW_LED 12
#define RED_LED 11

void setup() {
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  Serial.begin(9600);
  Serial.println("Serial Started...");
}

void loop() {
  float cm = distance();

  if (cm <= 10) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    Serial.println("Vermelho");
  } else if (cm <= 20) {
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("Amarelo");
  } else if (cm <= 50) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    Serial.println("Verde");
  } else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }

  delay(100);
}

float distance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  // A velocidade do som no ar é de aproximadamente 343 m/s ou 0.0343 cm/µs
  // A distância medida precisa ser dividida por 2 (ida e volta)
  float cm = duration * 0.0343 / 2;

  return cm;
}
