#include <Arduino.h>


/*NeoPixel-------------------------------------------------------------------------*/
#include <NeoPixelBus.h>
#define PIXEL_PIN 2
#define PIXEL_COUNT 7
NeoPixelBus<NeoGrbFeature, Neo800KbpsMethod> strip(PIXEL_COUNT, PIXEL_PIN);

double RR=0,GG=0,BB=255,BRT=1;
/*NeoPixel-------------------------------------------------------------------------*/


void setup() {
  /*シリアル初期化-----------------------------*/
   Serial.begin(115200);

   /*NeoPixel----------------------------------*/
    //NeoPixelBusのLEDの初期化
    strip.Begin();
    strip.Show();


}

void loop() {
  Serial.print("BRT = ");
  Serial.println(BRT);


  //LED配色設定
  Serial.print("RR = ");
  Serial.println(RR);
  Serial.print("GG = ");
  Serial.println(GG);
  Serial.print("BB = ");
  Serial.println(BB);


  /*NeoPixel*/
  //NeoPixelBus
  for(int i=0;i<PIXEL_COUNT;i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.SetPixelColor(i,RgbColor(RR,GG,BB)); // Moderately bright green color.
    //delay(delayval); // Delay for a period of time (in milliseconds).
  }
  strip.Show(); // This sends the updated pixel color to the hardware.


}
