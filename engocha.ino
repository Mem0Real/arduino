void setup() {
  Serial.begin(9600);

  pinMode(A5, INPUT_PULLUP);
  pinMode(9, INPUT);

  // Drag front 0, back 510 none 1021
  pinMode(A1, INPUT);
  // Tip front 512, back 10 none 1013
  pinMode(A2, INPUT);
  pinMode(A6, INPUT);
  pinMode(A7, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  // pinMode(12, INPUT_PULLUP);


  // Attach Components
  plotter.attach(3);
  lid.attach(4);
  drag.attach(8);
  tilt.attach(10);
  tip.attach(11);
  conveyor.attach(12);

  // Attach Interrupt
  attachInterrupt(0, INTERRUPTER, RISING);
  Setpoint = 150;
  myPID.SetMode(AUTOMATIC);

  defPosition();
}

void loop() {
  int checkStart = digitalRead(startBtn);
  totalTime = millis();
  // If run for firsttime, check default state is attained
  if (firstRun == true) {
    if (defState == false) {
      tdtDefault();
    } else {
      if (checkStart == 0) {
        start = true;
      }
    }
    // If start button is clicked, begin baking(after default)
    if (start == true) {
      bake(timeTillStart);
    } else {
      timeTillStart = millis();
    }
  } else {
    if (defState == false) {
      tdtDefault();
    } else {

      if (infrared2 == false) {
        irs();
        timeTillInfrared2 = millis();
      } else {
        lay(timeTillInfrared2);
      }
      
      if (infrared == false) {
        irSensor();
        timeTillInfrared = millis();
      } else {
        bake(timeTillInfrared);
      }
    }
  }
}