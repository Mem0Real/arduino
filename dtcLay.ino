void dtcLay() {
  int dState = analogRead(dragBtn);

  if (dragFrontBtn == true && dragBackBtn == true) {
    layCycle = true;
  } else {

    if (dragBack == true) {
      if (dragBackBtn == false) {
        dragBackward();
        // If back drag btn is touched
        if (dState >= 400 && dState <= 600) {
          dragBackBtn = true;
        }
        tiltReallyDown();
      } else {
        dragBack = false;
      }
    } else if (dragFront == true) {
      tiltUp();
      conveyorStop();


      if (dragFrontBtn == false) {
        dragForward();

        // If front drag btn is touched
        if (dState >= 0 && dState <= 20) {
          dragFrontBtn = true;
        }
      } else {
        dragFront = false;
      }
    }
  }
}