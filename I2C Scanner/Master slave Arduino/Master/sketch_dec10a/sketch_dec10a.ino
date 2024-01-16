#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 Oled = Adafruit_SSD1306(128, 64, &Wire);

#define SLAVE_ASSR 9
#define ANSWERSIZE 10

void setup() {
  Serial.begin(9600);
  Oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Display("I2C Master Demonstration");
}

void loop() {
  delay(50);

  Wire.beginTransmission(SLAVE_ASSR);
  Wire.write(0);
  Wire.endTransmission();

  // Oled.clearDisplay();
  // Oled.setTextColor(WHITE);
  // Oled.setTextSize(2);
  // Oled.setCursor(0, 0);
  // Oled.println("Receiving data");
  Display("Receving data");
  
  Wire.requestFrom(SLAVE_ASSR, ANSWERSIZE);

  String response = "";
  while (Wire.available()){
    char b = Wire.read();
    response += b;
  }

  Display(response);
}

void Display(String message) {
  Oled.clearDisplay();
  Oled.setTextColor(WHITE);
  Oled.setTextSize(2);
  Oled.setCursor(0, 0);
  Oled.println(message);
  Oled.display();
  Oled.invertDisplay(false);

  delay(500);
}
