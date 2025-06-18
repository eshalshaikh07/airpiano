#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define TRIG_PIN 5
#define ECHO_PIN 18

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("OLED init failed"));
    while(1);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

long getDistance() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

String getNoteFromDistance(long d) {
  if (d < 5 || d > 30) return "";
  if (d <= 8) return "C4";
  else if (d <= 12) return "D4";
  else if (d <= 16) return "E4";
  else if (d <= 20) return "F4";
  else if (d <= 24) return "G4";
  else return "A4";
}

void loop() {
  long distance = getDistance();
  String note = getNoteFromDistance(distance);

  display.clearDisplay();
  display.setCursor(0, 20);
  display.print("Note: ");
  display.print(note);
  display.display();

  if (note != "") {
    Serial.println(note);
    delay(300); // debounce
  }
  delay(100);
}
