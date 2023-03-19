void bake(unsigned long int tts) {

  int dState = analogRead(dragBtn);
  int tState = analogRead(tipBtn);

  timer1 = millis() - tts;
  // Serial.println(timer1);

  // Griddle On, Plotter In then Out & Pump On then Off.
  if (timer1 >= 500 && timer1 < 7000) {
    griddleOn();
    if (timer1 >= 2000 && timer1 <= 4000) {
      plotterIn();

    } else if (timer1 > 4000 && timer1 < 7000) {
      plotterOut();
      if (timer1 > 5500 && timer1 < 7000) {
        pumpOff();
      } else {
        pumpOn();
      }
    }
  }

  // Griddle Off then Waiting Time
  else if (timer1 >= 7000 && timer1 <= 12000) {
    griddleOff();
    Serial.println("Waiting Time");
  }

  // Close Lid
  else if (timer1 > 12000 && timer1 <= 14000) {
    closeLid();
  }

  // Baking Time
  else if (timer1 > 14000 && timer1 <= 18000) {
    Serial.println("Baking Time");
  }

  // Open Lid
  else if (timer1 > 18000 && timer1 <= 33000) {
    openLid();
    if (timer1 > 21000) {
      takeOut();
      if (takeoutMan == false) {
        resetBools();
      }
    }
  }
}