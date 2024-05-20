float PulseSensorPurplePin = 0;
unsigned long lastBeatTime = 0;

int BPM = 0;
int Signal;
float Pre_Filtered_Signal;
float Filtered_Signal;
float Pre_Signal = 0;

int Threshold = 350;

const float a2 = 0.7265;
const float b1 = 0.1367;
const float b2 = 0.1367;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Pre_Filtered_Signal = Filtered_Signal;
  Pre_Signal = Signal;
  
  Filtered_Signal = a2 * Pre_Filtered_Signal + b1 * Signal + b2 * Pre_Signal;
  
  if (Signal > Threshold) {
    unsigned long currentTime = millis();
    if (currentTime - lastBeatTime > 300) {
      unsigned long beatInterval = currentTime - lastBeatTime;
      BPM = 60000 / beatInterval;
      
      lastBeatTime = currentTime;

      Serial.print("BPM: ");
      Serial.println(BPM);  
    }
  }
}
