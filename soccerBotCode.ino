char t;

void setup() {
  pinMode(4, OUTPUT);   // Left motors forward
  pinMode(5, OUTPUT);   // Left motors reverse
  pinMode(6, OUTPUT);   // Right motors forward
  pinMode(7, OUTPUT);   // Right motors reverse
  Serial.begin(38400);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);
  }
 
  if (t == 'B') {           // Move forward (all motors rotate in forward direction)
   digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  else if (t == 'F') {      // Move reverse (all motors rotate in reverse direction)
   digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else if (t == 'R') {      // Turn left (left motors forward, right motors reverse)
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);

    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
  else if (t == 'L') {      // Turn right (right motors forward, left motors reverse)
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);
  }
  else if (t == 'S') {      // STOP (all motors stop)
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }


}
