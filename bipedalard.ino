#include <Servo.h>

Servo waist1;
Servo waist2;
Servo knee1;
Servo knee2;

int w1p = 90;//waist1position
int w2p = 90;//wasit2position
int k1p = 90;//knee1position
int k2p = 90;//knee2position
void setup() {

  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  waist1.attach(9);
  waist2.attach(10);
  knee1.attach(11);
  knee2.attach(12);

}
int speed = 10;
void loop() 
{
  // check for incoming serial data:
  if (Serial.available() > 0) 
  {
    // read incoming serial data:
    String inString = Serial.readStringUntil('Z');

    Serial.write("received: ");
    char buffer[256];
    inString.getBytes(buffer, 256); // 0x41 'N', 'D', 'R', 'E', 'W', 0x00
    Serial.write(buffer);
    Serial.write("\n");

    if(inString.startsWith("FB"))
    {
      Serial.write("Moving Forward!\n");
      inString.remove(0, 2);
      w1p = w1p + speed * inString.toFloat();
    }

      
    if(w1p > 180)
      w1p = 180;
    if(w1p < 0)
      w1p = 0;
    if(w2p > 180)
      w2p = 180;
    if(w2p < 0)
      w2p = 0;

    waist1.write(w1p);
    waist2.write(180 - w1p);
    knee1.write(w1p);
    knee2.write(180 - w1p);

  }

}