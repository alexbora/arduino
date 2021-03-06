#include <NewPing.h>

#define TRIG_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 58 //40
#define COLL_DIST 16 // distanta de coliziune la care robot stop si inapoi este de : 20cm
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);


// L298n module
// 1(+)inainte dreapta = DrFr
// 2(+)inapoi dreapta = DrSp
// 3(+)inainte stanga = StFr
// 4(+)inapoi stanga = StSp

int DrFr = 3;
int DrSp = 2;
int StFr = 4;
int StSp = 5;

const int pingPin = 7;
long duration, inches, cm;

void setup() {
//pinMode(LED_BUILTIN, OUTPUT);
pinMode(13, OUTPUT);
Serial.begin(9600);

pinMode(DrFr,OUTPUT);
pinMode(StFr,OUTPUT);
pinMode(DrSp,OUTPUT);
pinMode(StSp,OUTPUT);
digitalWrite(DrFr,LOW);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,LOW);
}

int scan() {
return (sonar.ping() / US_ROUNDTRIP_CM); //masurare distanta in cm
}

void loop() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
//inches = microsecondsToInches(duration);
 // cm = microsecondsToCentimeters(duration);
  cm = ( duration / 29 ) / 2;

 int Dist = scan(); // masuram distanta curenta

// Serial.println(Dist);
if (  scan() < COLL_DIST ) { // daca distanta curenta < decit distanta de coliziune
//PORTB=0b00100000;
//PORTB &= ~(0b00100000);
//PORTB^=PORTB;
moveStop();
delay(500);
moveBackward();
delay(500);
turnLeft();
delay(500);
} else {
//PORTB=0b00000000;
moveForward();
Dist = cm;
}
}

void moveStop() {
digitalWrite(DrFr,LOW);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,LOW);
//int Dist = scan();
//digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
 //delay(1000);                       // wait for a second
  //digitalWrite(13, LOW); 
}

void moveForward() {
digitalWrite(DrFr,HIGH);
digitalWrite(StFr,HIGH);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,LOW);


//digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
//delay(500);                       // wait for a second
//digitalWrite(13, LOW); 

}

void moveBackward()
{
digitalWrite(DrFr,LOW);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,HIGH);
digitalWrite(StSp,HIGH);
 
  //digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
 // delay(1000);                       // wait for a second
  //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
 //delay(1000); 

}

void turnRight()
{
digitalWrite(DrFr,LOW);
digitalWrite(StFr,HIGH);
digitalWrite(DrSp,HIGH);
digitalWrite(StSp,LOW);
}

void turnLeft()
{
digitalWrite(DrFr,HIGH);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,HIGH);
}

 

//??????????????????????????????-
