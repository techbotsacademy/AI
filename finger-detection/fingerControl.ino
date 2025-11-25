#include <Servo.h>

Servo servo_6;
char receivedChar;   // Store incoming serial data
char previousChar;   // Store incoming serial data

void setup()
{
  Serial.begin(9600);     // Match baud rate with JS serial connection
  pinMode(13,OUTPUT);
  servo_6.attach(6, 500, 2500);
}

void loop()
{
  if (Serial.available() > 0) {
    receivedChar = Serial.read();
    if(previousChar==receivedChar)
      return;

    if (receivedChar == 'O') {   
      // Wheel detected → Light ON
      servo_6.write(0);
    }
    else{
      servo_6.write(90);
    }
  }
//  delay(1000); // Wait for 1000 millisecond(s)
}
