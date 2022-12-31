#include <Adafruit_GFX.h>  // Include the Adafruit GFX library
//#include <TFT_eSPI.h>     // Include the TFT_eSPI library
#include <Adafruit_ST7789.h>
#include <SPI.h>

// Create a global instance of the TFT_eSPI object
//TFT_eSPI tft = TFT_eSPI();

Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  // Initialize the TFT display
  //tft.begin();
  Serial.begin(115200);

    // turn on backlite
  pinMode(TFT_BACKLITE, OUTPUT);
  digitalWrite(TFT_BACKLITE, HIGH);

  // turn on the TFT / I2C power supply
  pinMode(TFT_I2C_POWER, OUTPUT);
  digitalWrite(TFT_I2C_POWER, HIGH);
  delay(10);

  // initialize TFT
  tft.init(135, 240); // Init ST7789 240x135
  tft.setRotation(3);
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextSize(2);
}

void loop() {
  // Clear the display
  //tft.fillScreen(TFT_BLACK);
  tft.fillScreen(ST77XX_BLACK);

  // Draw a series of vertical lines with varying shades of red, orange, and yellow
  for (int x = 0; x < tft.width(); x++) {
    int color = random(0xF800, 0xFFE0);  // Generate a random color in the range of red, orange, and yellow
    tft.drawFastVLine(x, 0, tft.height(), color);  // Draw a vertical line with the generated color
  }

  // Wait a short time before updating the display again
  delay(50);
}