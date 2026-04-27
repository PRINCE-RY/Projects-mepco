const int ledPin = 9;       // PWM pin connected to the LED
const int buttonPin = 2;   // Pin connected to the switch
int brightness = 0;       // Variable to store the brightness level
int fadeAmount = 5;         // Amount to change the brightness each time
bool buttonState = 0;
void setup() {
  pinMode(ledPin, OUTPUT);      
  pinMode(buttonPin, INPUT);
}

void loop() {
    buttonState = digitalRead(buttonPin); // Read the state of the button
if (buttonState == HIGH) { // If the button is pressed
    brightness += fadeAmount; // Increase brightness

    if (brightness &lt;= 0 || brightness &gt;= 255)
{ // Reverse direction at limits
      fadeAmount = -fadeAmount;
    }
    analogWrite(ledPin, brightness); // Set the brightness of the LED
    delay(30);
}
