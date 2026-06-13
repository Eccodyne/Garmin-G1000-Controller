// Mega 2560: report meaningful events on all digital inputs and analog A0/A1
// English output, debounced edges for digital, thresholded/rate-limited for analog

// ---------------- Configuration ----------------

// Digital input pins to monitor (exclude 0/1 used by Serial)
const uint8_t digitalInputPins[] = {
  2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,
  22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
  34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53
};

// Only A0 and A1 are monitored
const uint8_t analogInputPins[] = { A0, A1 };

// Digital debounce (ms)
const unsigned long debounceMs = 25;

// Analog change threshold (0–1023). Raise if still noisy.
const int analogChangeThreshold = 100;

// Minimum time between analog reports per channel (ms)
const unsigned long analogReportIntervalMs = 120;

// Loop delay (ms)
const unsigned long loopDelayMs = 5;

// ---------------- State ----------------
struct DigitalState {
  uint8_t pin;
  int lastStable;        // HIGH/LOW
  int lastRead;          // last instantaneous read
  unsigned long lastChangeTime;
};

struct AnalogState {
  uint8_t pin;
  int lastValue;                  // last reported value
  unsigned long lastReportTime;   // for rate limiting
};

DigitalState dStates[sizeof(digitalInputPins)];
AnalogState aStates[sizeof(analogInputPins)];

// ---------------- Helpers ----------------
void setupDigitalInputs() {
  for (size_t i = 0; i < sizeof(digitalInputPins); i++) {
    uint8_t p = digitalInputPins[i];
    pinMode(p, INPUT_PULLUP);              // assumes button to GND
    int v = digitalRead(p);
    dStates[i] = { p, v, v, millis() };
  }
}

void setupAnalogInputs() {
  // Optional: perform a dummy read for settling
  for (size_t i = 0; i < sizeof(analogInputPins); i++) {
    uint8_t p = analogInputPins[i];
    analogRead(p);
    int v = readSmoothed(p);
    aStates[i] = { p, v, 0 };
  }
}

int readSmoothed(uint8_t pin) {
  // Simple 4-sample average to reduce noise
  long sum = 0;
  sum += analogRead(pin);
  sum += analogRead(pin);
  sum += analogRead(pin);
  sum += analogRead(pin);
  return (int)(sum / 4);
}

void reportDigitalEvent(uint8_t pin, bool pressed) {
  Serial.print("Digital pin ");
  Serial.print(pin);
  if (pressed) {
    Serial.println(" PRESSED");
  } else {
    Serial.println(" RELEASED");
  }
}

void reportAnalogChange(uint8_t pin, int value) {
  int aIndex = pin - A0; // 0 for A0, 1 for A1
  Serial.print("Analog pin A");
  Serial.print(aIndex);
  Serial.print(" value: ");
  Serial.println(value);
}

// ---------------- Arduino setup/loop ----------------
void setup() {
  Serial.begin(115200);
  while (!Serial) { /* wait for USB serial (optional) */ }

  setupDigitalInputs();
  setupAnalogInputs();

  Serial.println("Input monitor started. Reporting only meaningful events...");
  Serial.println("Digital: edges only (PRESSED/RELEASED). Analog: significant changes on A0/A1.");
}

void loop() {
  unsigned long now = millis();

  // Scan digital inputs with debounce and edge reporting
  for (size_t i = 0; i < sizeof(digitalInputPins); i++) {
    DigitalState &st = dStates[i];
    int raw = digitalRead(st.pin);

    if (raw != st.lastRead) {
      st.lastRead = raw;
      st.lastChangeTime = now; // reset debounce timer
    }

    if ((now - st.lastChangeTime) >= debounceMs && raw != st.lastStable) {
      st.lastStable = raw;
      bool pressed = (raw == LOW); // with INPUT_PULLUP, LOW = pressed
      reportDigitalEvent(st.pin, pressed);
    }
  }

  // Scan analog inputs A0/A1, report only significant, rate-limited changes
  for (size_t i = 0; i < sizeof(analogInputPins); i++) {
    AnalogState &as = aStates[i];
    int v = readSmoothed(as.pin);

    if (abs(v - as.lastValue) >= analogChangeThreshold) {
      if (now - as.lastReportTime >= analogReportIntervalMs) {
        as.lastValue = v;
        as.lastReportTime = now;
        reportAnalogChange(as.pin, v);
      }
    }
  }

  delay(loopDelayMs);
}
