void takeOut() {
  int tState = analogRead(tipBtn);

  // If we want the tip to go forward
  if (moveIn == true) {
    if (tipFrontBtn == false) {
      tipForward();

      // If front tip button is touched
      if (tState >= 400 && tState <= 600) {
        tipStop();
        tipFrontBtn = true;
      }
    } else {
      moveIn = false;
    }
  } else if (moveOut == true) {
    conveyorBack();
    // If we want the tip to go backward
    if (tipBackBtn == false) {
      tipBackward();

      // If back tip button is touched
      if (tState >= 0 && tState <= 100) {
        tipStop();
        tipBackBtn = true;
      }
    } else {
      moveOut = false;
    }
  } else {
    takeoutMan = false;
  }
}
