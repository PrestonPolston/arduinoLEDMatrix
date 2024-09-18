#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

int br = 115200;
int i;
int j;
int delayTime = 50;

String message = "   Hello world!!!";

byte frame[8] [12]={
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0}
};

void setup() {
  Serial.begin(br);
  matrix.begin();
}


void loop() {
  // logic for graphics
  // matrix.beginDraw();
  // matrix.textScrollSpeed(100);
  // matrix.textFont(Font_5x7);
  // matrix.beginText(0, 1, 255, 0, 0);
  // matrix.println(message);
  // matrix.endText(SCROLL_LEFT);
  // matrix.endDraw();

  // logic for bitmap
  for(i = 0 ; i <= 11 ; i = i + 1){
    for(j = 0 ; j <= 7 ; j = j + 1){
    frame[j][i] = !frame[j][i];}
      matrix.renderBitmap(frame, 8, 12);
      delay(delayTime);
  }

}
