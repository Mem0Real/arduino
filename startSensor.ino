void startSensor() {
  int checkStart = digitalRead(startBtn);
  if (checkStart == 0) {
    Serial.print("Started");
    start = true;
  }
}