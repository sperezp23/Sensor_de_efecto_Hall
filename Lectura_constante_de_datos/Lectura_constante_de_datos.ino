// These constants won't change. They're used to give names to the pins used:
 
const int analogInPin = A0; // Analog input pin that the potentiometer is attached to 
float sensorValue = 0.0; // value read from the pot 
float outputValue = 0.0; // value output to the PWM (analog out) 

void setup() { 
  // initialize digital pin LED_BUILTIN as an output. 
  pinMode(LED_BUILTIN, OUTPUT); 

  // initialize serial communications at 9600 bps: 
  Serial.begin(9600); 

  //Referencia analógica PIN AREF 
  analogReference (DEFAULT); 

} 

void loop() { 
  // turn the LED on (HIGH is the voltage level) 
  digitalWrite(LED_BUILTIN, HIGH); 

  // read the analog in value: 
  sensorValue = analogRead(analogInPin); 

  // map it to the range of the analog out: 
  outputValue = (sensorValue * 5.0) / 1023.0; 

  // print the results to the Serial Monitor: 
  Serial.print("sensor = "); 
  Serial.print(sensorValue); 
  Serial.print("\t output = "); 
  Serial.println(outputValue); 

  // wait 2 milliseconds before the next loop for the analog-to-digital 
  // converter to settle after the last reading: 
  delay(4);
  }