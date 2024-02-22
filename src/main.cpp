#include <Arduino.h>

// RESET PIN = 8
// BOOT PIN = 7
// pinMode Input -> floating Pin
long currentmillis = millis();

void setup()
{
  // Initialize serial communication at 9600 baud
  Serial.begin(9600);
  Serial.println("//////////////////////////////////////////");
  Serial.println("// Project: K1-ButtonSerial");
  Serial.println("// Version: v1.0.0");
  Serial.println("// Author: Tim Fischbach");
  Serial.println("//////////////////////////////////////////");
  pinMode(7, INPUT);
  delay(200);
  pinMode(8, INPUT);
  delay(2000);
}

void loop()
{

  // Check if data is available to read from serial port
  if (Serial.available() > 0)
  {
    // Read the incoming byte
    char incomingByte = Serial.read();

    // Check the received character
    if (incomingByte == 'r')
    {
      Serial.println("Resetting Board...");
      digitalWrite(8, LOW);
      pinMode(8, OUTPUT);
      delay(200);
      pinMode(8, INPUT);
      Serial.println("DONE!");
    }
    else if (incomingByte == 'b')
    {
      Serial.println("Resetting Board into Boot Mode...");
      digitalWrite(8, LOW);
      pinMode(8, OUTPUT);
      digitalWrite(7, HIGH);
      pinMode(7, OUTPUT);
      delay(200);
      pinMode(8, INPUT);
      delay(200);
      pinMode(7, INPUT);
      Serial.println("DONE!");
    }
  }
  if (currentmillis + 1000 < millis())
  {
    currentmillis = millis();
    Serial.write(27);    // ESC command
    Serial.print("[2J"); // clear screen command
    Serial.write(27);
    Serial.print("[H"); // cursor to home command
    Serial.println("==========================================");
    Serial.println("Press R to reset the Board");
    Serial.println("Press B to reset the Board into Boot Mode");
    Serial.println("==========================================");
  }
}