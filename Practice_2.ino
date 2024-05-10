int PulseSensorPurplePin = 0;
int Signal;
int LED = 13;
int Threshold = 450;
int LED_H = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Serial.print(Signal);
  Serial.print(" ");

  if(Signal > Threshold) {
    digitalWrite(LED,HIGH);
    LED_H = 1023;
  }
  else {
    digitalWrite(LED,LOW);
    LED_H = 0;
  }
  Serial.println(LED_H);
}
