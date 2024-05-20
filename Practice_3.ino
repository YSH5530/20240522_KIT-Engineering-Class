int PulseSensorPurplePin = 0;
int Signal;
float Pre_Filtered_Signal;
float Filtered_Signal;
float Pre_Signal = 0;

const float a2 = 0.7265;
const float b1 = 0.1367;
const float b2 = 0.1367;

int LED = 13;
int Threshold = 360;
int LED_H = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Pre_Filtered_Signal = Filtered_Signal;
  Pre_Signal = Signal;
  
  Filtered_Signal = a2 * Pre_Filtered_Signal + b1 * Signal + b2 * Pre_Signal;
  
  Serial.print(Filtered_Signal);
  Serial.print(" ");

  if(Filtered_Signal > Threshold) {
    digitalWrite(LED,HIGH);
    LED_H = 400;
  } else {
    digitalWrite(LED,LOW);
    LED_H = 320;
  }
  Serial.println(LED_H);
}
