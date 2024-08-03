#include <Wire.h>

void setup() {
  Wire.begin(8); // Address #8
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  Serial.print("Data received from master: ");
  while (Wire.available()) {
    char c = Wire.read(); // Receive byte as char
    Serial.print(c);
  }
  Serial.println();
}

void requestEvent() {
  Wire.write("Khoury"); // Send data back to master
  Serial.println("Data sent to master: Khoury");
}
