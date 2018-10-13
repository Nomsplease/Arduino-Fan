void countPulse() {
  // just count each pulse we see
  // ISRs should be short, not like
  // these comments, which are long.
  pulses++;
}

unsigned long calculateRPM() {
  unsigned long RPM;
  noInterrupts();
  float elapsedMS = (millis() - lastRPMmillis)/1000.0;
  unsigned long revolutions = pulses/2;
  float revPerMS = revolutions / elapsedMS;
  RPM = revPerMS * 3.8;
  lastRPMmillis = millis();
  pulses=0;
  interrupts();
//  Serial.print(F("elpasedMS = ")); Serial.println(elapsedMS);
//  Serial.print(F("revolutions = ")); Serial.println(revolutions);
//  Serial.print(F("revPerMS = ")); Serial.println(revPerMS);
  return RPM;
}


