/*
   TUTORIAL PASSIVE BUZZER PADA ARDUINO
   D3 -> Passive Buzzer +



*/

#define pinBuzzer 3 //buzzer pada pin D3

void setup() {
  pinMode(pinBuzzer, OUTPUT); //set menjadi output
}

void loop() {
  for (int i = 0; i < 2; i++) {
    playTone(261.63, 350);
    delay(1000); 
  }
  for (int j = 0; j < 2; j++) {
    playTone(523.25, 350);
    delay(1000); 
  }
}


void playTone(long note, long millisecond) {
  long frequency = note;
  long length = millisecond;
  if (frequency > 0) {
    long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
    //// 1 second's worth of microseconds, divided by the frequency, then split in half since
    //// there are two phases to each cycle
    long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
    //// multiply frequency, which is really cycles per second, by the number of seconds to
    //// get the total number of cycles to produce
    for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
      digitalWrite(pinBuzzer, HIGH); // write the buzzer pin high to push out the diaphram
      delayMicroseconds(delayValue); // wait for the calculated delay value
      digitalWrite(pinBuzzer, LOW); // write the buzzer pin low to pull back the diaphram
      delayMicroseconds(delayValue); // wait again or the calculated delay value
    }
  }
  else delay(millisecond);
}
