//Tossapon puhin autopush 1.0
#define Trig 2
#define Echo 3
#include <Servo.h>
#include <avr/wdt.h>
Servo myservo;
long duration;
int distance;
int gtime;

void setup() {
myservo.attach(A0);
myservo.write(20);
pinMode(LED_BUILTIN, OUTPUT);
pinMode(Trig, OUTPUT);
pinMode(Echo, INPUT);
Serial.begin (115200);
delay(1000);
gtime = 0;
//Serial.println("boots ini"); 
}

void loop() {
digitalWrite(Trig, LOW);
delayMicroseconds(5);
digitalWrite(Trig, HIGH);
delayMicroseconds(10);
digitalWrite(Trig, LOW);
duration = pulseIn(Echo, HIGH);

distance = duration * 0.034 / 2;

// Serial.println(distance); 

gtime = gtime+1;

if (distance <= 12)
{
  digitalWrite(LED_BUILTIN, HIGH);
  myservo.write(130);
  delay(1000);
  gtime=0;
}
else {
  digitalWrite(LED_BUILTIN, LOW);
  myservo.write(20);
  delay(500);
}


if(gtime >= 30){
  gtime = 0;
  software_Reboot();
}

}

void software_Reboot()
{
  asm volatile ("jmp 0");

}
