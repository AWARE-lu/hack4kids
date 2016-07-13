/*
  Simple Metronome (RThurber) v1
  This example code is in the public domain.
  Initial source: https://gist.github.com/rthurber/18101567f05efc25d367
 */

// Pin 13 has an LED connected on most Arduino boards.
int led = 13;          // LED and Piezo
int sensorPin = 0;    // select the input pin for the potentiometer
int sensorValue = 0;
int metronomeBPM = 0;
int metronomePulse = 10;
int staticBPM = 60000;
int divisor  = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(led, HIGH);
  delay(metronomePulse);   // Use a 10 ms pulse for Piezo
  digitalWrite(led, LOW);
  delay(sensorValue);      // Take potentiometer as the metronome interval (offset 10ms).

  divisor = sensorValue + metronomePulse;
  metronomeBPM = 60000 / divisor;

  Serial.println(metronomeBPM);
}
