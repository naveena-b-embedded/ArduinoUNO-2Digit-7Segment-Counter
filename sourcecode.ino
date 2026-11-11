const int dataPin   = 2;   // DATA
const int clockPin  = 3;   // CLK
const int strobePin = 4;   // STRB

// Board reverse logic-na (common anode) idha true pannu
const bool INVERT = false;

// bit: 0=a 1=b 2=c 3=d 4=e 5=f 6=g 7=dp
const byte digits[10] = {
  0b00111111, // 0
  0b00000110, // 1
  0b01011011, // 2
  0b01001111, // 3
  0b01100110, // 4
  0b01101101, // 5
  0b01111101, // 6
  0b00000111, // 7
  0b01111111, // 8
  0b01101111  // 9
};

void send2(byte tens, byte ones) {
  if (INVERT) { tens = ~tens; ones = ~ones; }
  digitalWrite(strobePin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ones);  // first data = far digit
  shiftOut(dataPin, clockPin, MSBFIRST, tens);
  digitalWrite(strobePin, HIGH);
}

void showNumber(int n) {
  send2(digits[n / 10], digits[n % 10]);
}

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(strobePin, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 99; i++) {
    showNumber(i);
    delay(500);
  }
}
