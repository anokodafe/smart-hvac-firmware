// Smart HVAC - Arduino Nano firmware (rebuild)

const int NUM_ZONES = 4;
const int fanPins[NUM_ZONES] = {5, 6, 9, 10};
const int BUTTON_PIN = 2;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < NUM_ZONES; i++) {
    pinMode(fanPins[i], OUTPUT);
  }
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
}
