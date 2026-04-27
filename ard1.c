const int redLight = 2;
const int yellowLight = 3;
const int greenLight = 4;

void setup() {
  pinMode(redLight, OUTPUT);
  pinMode(yellowLight, OUTPUT);
  pinMode(greenLight, OUTPUT);
}

void loop() {
  digitalWrite(redLight, HIGH);
  delay(5000);
  digitalWrite(redLight, LOW);
digitalWrite(greenLight, HIGH);
  delay(5000);
  digitalWrite(greenLight, LOW);
  digitalWrite(yellowLight, HIGH);
  delay(2000);
  digitalWrite(yellowLight, LOW);
}
