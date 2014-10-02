#include <Servo.h>

Servo servo;
String serial;

void setup()
{
 servo.attach(9);
 
 
Serial.begin(9600);
Serial.println(" RORI - GLaDOs 1.0");
}

void loop()
{
  if(serial.length() > 0)
  {
    int v = (int)serial[0] - 48;
    Serial.println(v);
    servo.write(v*90);
    delay(500);
  }
  else
    servo.write(90);
  serial = serial.substring(1);
  Serial.println(serial.length());
}
