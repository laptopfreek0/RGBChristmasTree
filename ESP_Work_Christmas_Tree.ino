#include <NeoPixelBus.h>
#include <ESP8266WiFi.h>
 
//#define DEBUG
 
// Setup NeoPixel (Connected to RX Pin)
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(25,1); // means only 1 led
// Set Max Color
#define colorSaturation 128
#define pixelCount 12

RgbColor rgbColorsCurrent[pixelCount-1];
RgbColor rgbColorsTo[pixelCount-1];

void setup() {
  // put your setup code here, to run once:
 
  // Disable Wifi
  WiFi.forceSleepBegin();
 
  // Setup NeoPixel Strip to an off State
  strip.Begin();
  strip.Show();
  
  #ifdef DEBUG
    Serial.begin(115200);
    Serial.println("Started");
  #endif
}

void loop() {
  //modeChaserBounce();
  modeBlink();
  basicChase();
  
}

void modeBlink() {
  for (int i = 0; i < 5; i++) {
    _modeBlink(RgbColor(128,0,0), RgbColor(100,128,0));
    delay(2000);
    _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
    delay(500);
    _modeBlink(RgbColor(0,128,0), RgbColor(100,128,0));
    delay(2000);
    _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
    delay(500);
  }
  _modeBlink(RgbColor(100,80,128), RgbColor(100,128,0));
  delay(3000);
  _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
  delay(500);
  for (int i = 0; i < 5; i++) {
    _modeBlink(RgbColor(128,0,0), RgbColor(100,128,0));
    delay(4000);
    _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
    delay(500);
    _modeBlink(RgbColor(0,128,0), RgbColor(100,128,0));
    delay(4000);
    _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
    delay(500);
    _modeBlink(RgbColor(128,128,128), RgbColor(100,128,0));
    delay(4000);
    _modeBlink(RgbColor(0,0,0), RgbColor(0,0,0));
    delay(500);
  }
  _modeBlink(RgbColor(100,80,128), RgbColor(100,128,0));
  delay(6000);
}

void _modeBlink(RgbColor c, RgbColor t) {
  for (int i = 0; i < pixelCount-1; i++) {
    rgbColorsCurrent[i] = c;
  }
  rgbColorsCurrent[pixelCount-1] = t;
  setPixelStripColors();
}

void basicChase() {
  for (int i = 0; i < 10; i++) {
    _basicChase(RgbColor(128,0,0), RgbColor(100,128,0), 250);
    _basicChase(RgbColor(0,128,0), RgbColor(100,128,0), 250);
  }
  for (int i = 0; i < 5; i++) {
    _basicChase(RgbColor(128,0,0), RgbColor(100,128,0), 500);
    _basicChase(RgbColor(0,128,0), RgbColor(100,128,0), 500);
  }
}

void _basicChase(RgbColor c, RgbColor t, uint8_t wait) {
  for (int i = 0; i < pixelCount-1; i++) {
    blankColorArray();
    rgbColorsCurrent[i] = c;
    setPixelStripColors();
    delay(wait);
  }
  blankColorArray();
  rgbColorsCurrent[pixelCount-1] = t;
  setPixelStripColors();
  delay(wait);
}

void blankColorArray() {
  for (int i = 0; i < pixelCount; i++) {
    rgbColorsCurrent[i] = RgbColor(0,0,0);
  }
}

void modeChaserFill() {
  _modeChaserFill(RgbColor(128,128,128),100);
}

void _modeChaserFill(RgbColor c, uint8_t wait) {
  for (int i = 0; i < pixelCount; i++) {
    for (int j =0; j < pixelCount; j++) {
      
    }
  }
}

void setPixelStripColors() {
  for (int i = 0; i < pixelCount; i++) {
    strip.SetPixelColor(i, rgbColorsCurrent[i]);
  }
  strip.Show();
}


/********************************************************* */
void modeChaserBounce() {
  _colorWipe(RgbColor(128,128,128),100);
  _colorWipe(RgbColor(128,0,0),100);
  _colorWipe(RgbColor(0, 128, 0), 100);
  _colorWipe(RgbColor(0,0,128),100);
  _colorWipe(RgbColor(0,128,128),100);
  _colorWipe(RgbColor(128,0,128),100);
  _colorWipe(RgbColor(128,128,0),100);
}


void _colorWipe(RgbColor c, uint8_t wait) {
  for(uint16_t i=0; i<pixelCount; i++) {
    strip.SetPixelColor(i, c);
    strip.SetPixelColor(i+1, c);
    strip.SetPixelColor(i+2, c);
    strip.Show();
    strip.SetPixelColor(i, RgbColor(0,0,0));
    strip.SetPixelColor(i+1, RgbColor(0,0,0));
    strip.SetPixelColor(i+2, RgbColor(0,0,0));
    delay(wait);
  }

  for(uint16_t i=pixelCount; i>0; i--) {
    strip.SetPixelColor(i, c);
    strip.SetPixelColor(i+1, c);
    strip.SetPixelColor(i+2, c);
    strip.Show();
    strip.SetPixelColor(i, RgbColor(0,0,0));
    strip.SetPixelColor(i+1, RgbColor(0,0,0));
    strip.SetPixelColor(i+2, RgbColor(0,0,0));
    delay(wait);
  }
}
/********************************************************* */
