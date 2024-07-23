int tDelay = 500;
int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte leds = 0;

void updateShiftRegister() 
{
  // put your setup code here, to run once:
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);
}

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  leds = 0;
  updateShiftRegister();
  delay(tDelay*3);
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    bitSet(leds, i);
    updateShiftRegister();
    delay(tDelay);
    digitalWrite(LED_BUILTIN, LOW);
  }
}
