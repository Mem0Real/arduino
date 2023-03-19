void irs() {
  int checkInfrared = digitalRead(infraredSensor);
  // If infrared is touched
  if (checkInfrared == 0) {
    infrared2 = true;
  }
}