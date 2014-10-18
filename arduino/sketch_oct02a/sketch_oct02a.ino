#include <Servo.h>

Servo servo;
String serial;// = "0101010100101010100101010101010101010101";
char carlu = 0;

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
    Serial.println(serial);
    Serial.println(serial.length());
    Serial.println("-------------");
    servo.write(v*90);
    delay(100);    
    serial = serial.substring(1);
    Serial.println(serial);
  }
  else
    servo.write(90);
    
  while(Serial.available() > 0)
  {
    carlu = Serial.read();
    Serial.println("reçu");
    serial += carlu;
    delay(100);
  }
}
