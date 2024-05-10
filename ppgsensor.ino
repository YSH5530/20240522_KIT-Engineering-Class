int PulseSensorPurplePin = 0;
int Signal;

void setup() {
   Serial.begin(9600);
}

void loop() {
   Signal = analogRead(PulseSensorPurplePin);
   Serial.println(Signal);
}


int LED = 13;
int Threshold = 450;

  pinMode(LED,OUTPUT);

   if(Signal > Threshold){
     digitalWrite(LED,HIGH);
   } else {
     digitalWrite(LED,LOW);
   }
