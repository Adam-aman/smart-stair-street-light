int irSensor = 2;     // IR sensor OUT pin connected to D2
int lightPin = 3;     // LED or relay connected to D3

void setup() {
  pinMode(irSensor, INPUT);
  pinMode(lightPin, OUTPUT);
  digitalWrite(lightPin, HIGH);  // Start with light ON
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(irSensor);

  if (sensorValue == LOW) {
    // Object detected → turn OFF light
    digitalWrite(lightPin, LOW);
    Serial.println("Person detected - Light OFF");
  } else {
    // No object → turn ON light
    digitalWrite(lightPin, HIGH);
    Serial.println("No one - Light ON");
  }

  delay(300);  // Small delay to avoid flickering
}