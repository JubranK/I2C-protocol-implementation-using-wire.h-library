#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  // Send data to slave
  Wire.beginTransmission(8); // Address of the Arduino slave
  Wire.write("Jubran"); // Send data to slave
  Wire.endTransmission();
  Serial.println("Data sent to Arduino-slave: Jubran");

  delay(1000);

  // Request data from slave
  Wire.requestFrom(8, 6); 
  Serial.print("Data received from Arduino-slave: ");
  
  while (Wire.available()) {
    char c = Wire.read(); // Receive byte as char
    Serial.print(c); 
  }
  Serial.println();

  delay(1000);
}
