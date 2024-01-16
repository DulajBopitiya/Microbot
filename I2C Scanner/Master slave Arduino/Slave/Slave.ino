#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWERSIZE 10 // Adjust the size to accommodate the response string

String answer = "Hello";
int counter = 1; // Start the counter at 1

void setup() {
  Wire.begin(SLAVE_ADDR);
  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Serial.println("I2C Slave Demonstration");
}

void loop() {
  // Your main code can go here
  delay(50);
}

void receiveEvent() {
  while (Wire.available() > 0) {
    byte x = Wire.read();
    // You can handle received data here if needed
  }
  Serial.println("Receive Event");
}

void requestEvent() {
  // Create a response string with "Hello-" and the counter value
  String response = answer + "-" + String(counter);
  
  // Convert the response string to a character array
  char responseArray[ANSWERSIZE];
  response.toCharArray(responseArray, ANSWERSIZE);

  // Send the response array
  Wire.write((byte*)responseArray, ANSWERSIZE);

  // Increment the counter for the next request
  counter++;

  Serial.println("Request Event");
}
