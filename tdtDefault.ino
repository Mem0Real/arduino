void tdtDefault() {

  int dState = analogRead(dragBtn);
  int tState = analogRead(tipBtn);

  if(tState >= 0 && tState <= 100) {
    tdState = true;
    tipStop();
  }
  if(dState >= 0 && dState <= 50) {
    ddState = true;
    dragStop();
  } 

  if(ddState == true && tdState == true) {
    defState = true;
  } else {
    if(tdState == false) {
      tipBackward();
    }
    if(ddState == false) {
      dragForward();
    }
  }
}