void irSensor() {
  int checkInfrared = digitalRead(infraredSensor);

  // If infrared is touched
  if (checkInfrared == 0) {
    infrared = true;
  }
}