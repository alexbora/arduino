#include <NewPing.h>

#define TRIG_PIN 8
#define ECHO_PIN 7
#define MAX_DISTANCE 400
#define COLL_DIST 20 // distanta de coliziune la care robot stop si inapoi este de : 20cm
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

void setup() {
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
int Dist = scan(); // masuram distanta curenta
// Serial.println(Dist);
if (( Dist > 0 ) || ( Dist < COLL_DIST )) { // daca distanta curenta < decit distanta de coliziune
moveStop();
moveBackward();
delay(500);
turnRight();
delay(300);
} else {
moveForward();
}
}

void moveStop() {
digitalWrite(DrFr,LOW);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,LOW);
}

void moveForward() {
digitalWrite(DrFr,HIGH);
digitalWrite(StFr,HIGH);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,LOW);
}

void moveBackward() {
digitalWrite(DrFr,LOW);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,HIGH);
digitalWrite(StSp,HIGH);
}

void turnRight() {
digitalWrite(DrFr,LOW);
digitalWrite(StFr,HIGH);
digitalWrite(DrSp,HIGH);
digitalWrite(StSp,LOW);
}

void turnLeft() {
digitalWrite(DrFr,HIGH);
digitalWrite(StFr,LOW);
digitalWrite(DrSp,LOW);
digitalWrite(StSp,HIGH);
}

 

//––––––––––-
