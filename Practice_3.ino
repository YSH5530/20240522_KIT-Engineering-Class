#define ts 0.001 * 0.001

float PulseSensorPurplePin = 0;
unsigned long tCount = 0;
unsigned long tCountPre = 0;

float Signal = 0;
float Signal_pre = 0;
float diff_Signal = 0;
float dt = 0;


void setting() {
  tCount = micros();
  Signal = analogRead(PulseSensorPurplePin);
  dt = (float)(tCount - tCountPre) * ts;
}

void saveStates() {
  Signal_pre = Signal;
  tCountPre = tCount;
}
void firstDerivative() {
  diff_Signal = (Signal - Signal_pre) / dt;
}

void getData() {
  setting();
  firstDerivative();
  saveStates();
}

void setup()
{
  Serial.begin(9600);
}

void loop() {
  getData();
  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(diff_Signal);
}
