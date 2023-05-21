# include <SoftwareSerial.h>
# include <Servo.h>


#define forward 8
#define forward2 11
#define backward 9
#define backward2 10



void setup() {
  // put your setup code here, to run once:

pinMode(forward, OUTPUT);
pinMode(backward,OUTPUT);
pinMode(forward2, OUTPUT);
pinMode(backward2,OUTPUT);


}
 
void loop() {
  // put your main code here, to run repeatedly:

analogWrite(forward,255);
analogWrite(forward2,255);
delay(6000);
analogWrite(forward,0);
analogWrite(forward2,0);
}
