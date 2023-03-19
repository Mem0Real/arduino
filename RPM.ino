void RPM() {
  delay(300);
  detachInterrupt(0);
  TIME = millis() - PREVIOUS;
  RPM_VALUE = (REV / TIME) * (60000 / 56);
  PREVIOUS = millis();
  REV = 0;
  Serial.println(RPM_VALUE);
  attachInterrupt(0, INTERRUPTER, RISING);
  Input = RPM_VALUE;
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.print("SP: ");
  Serial.println(Setpoint);
  Serial.print("\tPV: ");
  Serial.println(Input);
  Serial.print("OP: ");
  Serial.println(Output);
}