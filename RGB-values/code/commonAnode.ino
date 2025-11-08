// Arduino RGB LED color controller via Serial
// Expected input format: R,G,B (e.g., 255,100,50)

const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();  // remove whitespace or newlines

    int comma1 = input.indexOf(',');
    int comma2 = input.lastIndexOf(',');

    if (comma1 > 0 && comma2 > comma1) {
      int r = input.substring(0, comma1).toInt();
      int g = input.substring(comma1 + 1, comma2).toInt();
      int b = input.substring(comma2 + 1).toInt();

      analogWrite(redPin, 255-r);
      analogWrite(greenPin, 255-g);
      analogWrite(bluePin, 255-b);
    } else {
      Serial.println("Invalid format. Use R,G,B");
    }
  }
}

