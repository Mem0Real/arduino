void lay(unsigned long int tts) {

  int dState = analogRead(dragBtn);

  timer2 = millis() - tts;

  if (timer2 >= 0) {
    // conveyorStop();

    if (timer2 >= 0 && timer2 < 1000) {
      Serial.println("Tilting Down");
      tiltDown();
    }

    else if (timer2 > 1000 && timer2 < 4000) {
      tiltDown();
      conveyorForward();
      Serial.println("Tilting Down & conveyor forward");
    }

    if (timer2 >= 1000) {
      // Start laying maneuver
      dtcLay();
      if (layCycle == true) {
        resetLays();
      }
    }
  }
}