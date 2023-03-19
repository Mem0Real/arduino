// Plotter In
void plotterIn() {
  plotter.write(0);
  Serial.println("Plotter going in");
}

// Plotter Out
void plotterOut() {
  plotter.write(150);
  Serial.println("Plotter going out");
}

// Open Lid
void openLid() {
  lid.write(75);
  Serial.println("Lid opening");
}

// Close Lid
void closeLid() {
  lid.write(115);
  Serial.println("Lid closing");
}

// Drag Forward
void dragForward() {
  drag.write(80);
  Serial.println("Dragging forward");
}

// Stop Drag
void dragStop() {
  drag.write(92);
  Serial.println("Dragging stopped");
}

// Drag Backwards
void dragBackward() {
  drag.write(100);
  Serial.println("Dragging backwards");
}

// Forward Tip
void tipForward() {
  tip.write(180);
  Serial.println("Tip going forward");
}

// Stop Tip
void tipStop() {
  tip.write(89);
  Serial.println("Tip stopped");
}

// Tip Backward
void tipBackward() {
  tip.write(0);
  Serial.println("Tip going backwards");
}

// Turn Griddle On
void griddleOn() {
  // PID_Control();  //calls the PID function every T interval and outputs a control signal
  // Serial.println("Griddle on");
  RPM();
}

// Turn Griddle Off
void griddleOff() {
  Serial.println("Griddle off");
}

// Turn Pump On
void pumpOn() {
  Serial.println("Pump on");
}

// Turn Pump Off
void pumpOff() {
  Serial.println("Pump off");
}

// Move Tilt Up
void tiltUp() {
  tilt.write(90);
  Serial.println("Tilting up");
}

// Move Tilt Down
void tiltDown() {
  tilt.write(50);
  Serial.println("Tilting down");
}

// Move Tilt Really Down
void tiltReallyDown() {
  tilt.write(45);
  Serial.println("Tilting really down");
}

// Move Conveyor Backwards
void conveyorBack() {
  conveyor.write(0);
  Serial.println("Conveyor rotating backwards");
}

// Stop Moving Conveyor
void conveyorStop() {
  conveyor.write(90);
  Serial.println("Conveyor stopped rotating");
}

// Move Conveyor Forward
void conveyorForward() {
  conveyor.write(180);
  Serial.println("Conveyor rotating forward");
}