/* Statement of Authorship COMP-10184-01: I Gustavo Jose Marcano, 000812644 certify
that this material is my original work. No other person's work has been used without 
due acknowledgement. I have not made my work available to anyone else. */

#include <Arduino.h>

void setup() {
  // configure the USB serial monitor
  Serial.begin(115200);
}

// function to convert digital input signal 
// to analog representation (modeling voltage)
float digitalToAnalogConverterVoltage(int analogValue) {
  return (3.3/1023) * analogValue;
}

// function to convert digital input signal 
// to analog representation (modeling temperature)
float digitalToAnalogConverterTemperature(int analogValue) {
  return (50.0/1023) * analogValue;
}

void loop() {
  int iVal;
  String message="";

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);

  float temperature = digitalToAnalogConverterTemperature(iVal);
  if(temperature < 10)
    message="Cold!";
  else if(temperature >= 10 && temperature < 15)
    message="Cool";
  else if(temperature >= 15 && temperature < 25)
    message="Perfect";
  else if(temperature >=25 && temperature < 30)
    message="Warm";
  else if(temperature >=30 && temperature < 35)
    message="Hot";
  else if(temperature >=35)
    message="Too hot";

  //print the value to the USB port
  // Serial.println("Digitized Value = " + String(iVal) + 
  //   " is equivalent to an Analog Voltage = " + 
  //   digitalToAnalogConverterVoltage(iVal) + "V");


  Serial.println("Digitized output of " + String(iVal) + 
    " is equivalent to a temperature of input of = " 
    + temperature + " deg. C, which is "+
    message);


  delay(2000);
}