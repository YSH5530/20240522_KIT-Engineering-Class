#define ts 0.001 * 0.001

float PulseSensorPurplePin = 0;
unsigned long tCount = 0;
unsigned long tCountPre = 0;

float Signal = 0;
float diff_Signal = 0;
float dt = 0;

float Pre_Filtered_Signal;
float Filtered_Signal;
float Pre_Signal = 0;
float Pre_diff = 0;

const float a2 = 0.7265;
const float b1 = 0.1367;
const float b2 = 0.1367;

void setting() {
  tCount = micros();
  Signal = analogRead(PulseSensorPurplePin);
  dt = (float)(tCount - tCountPre) * ts;
}

void saveStates() {
  Pre_Signal = Signal;
  tCountPre = tCount;
}
void firstDerivative() {
  diff_Signal = (Signal - Pre_Signal) / dt;
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
  Pre_Filtered_Signal = Filtered_Signal;
  Pre_diff = diff_Signal;
  
  Filtered_Signal = a2 * Pre_Filtered_Signal + b1 * diff_Signal + b2 * Pre_diff;
  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(Filtered_Signal);
}
