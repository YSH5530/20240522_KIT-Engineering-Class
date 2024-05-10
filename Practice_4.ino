#include <PulseSensorPlayground.h>

int PulseWire = 0; 
int LED = 13; 
int Threshold = 450;       
                               
PulseSensorPlayground pulseSensor; 

void setup() {   

  Serial.begin(9600);  

  pulseSensor.analogInput(PulseWire);   
  pulseSensor.setThreshold(Threshold);   

   if (pulseSensor.begin()) {
    Serial.println("start");
  }
}

void loop() {

if (pulseSensor.sawStartOfBeat()) {           
int myBPM = pulseSensor.getBeatsPerMinute(); 
                                            
 Serial.print("BPM: ");                      
 Serial.println(myBPM);                      
 }
}

  
