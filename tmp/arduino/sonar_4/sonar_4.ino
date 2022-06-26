// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>
/* #include <time.h> */
/* #include <avr/io.h> */
/* #include <util/delay.h> */


#define TRIGGER_PIN 8                // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN 7 // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 400 // Maximum distance we want to ping for (in centimeters). Maximum sensor
      // distance is rated at 400-500cm.

#define DELAY 500
/* #define NAKED __attribute__((naked)) */ 

/* static int last; */


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int EN_A = 9; // 4
int in1 = 2;  // stanga
int in2 = 3;

int EN_B = 10; // 3 // 10
int in3 = 4;   // dreapta
int in4 = 5;



void setup() {
  pinMode(13, OUTPUT);

  /* pinMode(EN_A, OUTPUT); */
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  /* pinMode(EN_B, OUTPUT); */
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  /* analogWrite(EN_A, 255); */
  /* analogWrite(EN_B, 255); */
  /* srand((unsigned long)time(0)); */
  Serial.begin(9600); 
}

void   fnull() { __asm__("nop"); }

void   ahead() {
  digitalWrite(in1, HIGH); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, HIGH); // dreapta fata
  digitalWrite(in3, LOW);
  /* analogWrite(EN_B, 100); */

  /* for (int i = 0; i < 256; i++) { */
  /* analogWrite(EN_B, i); */
  /* analogWrite(EN_A, i); */
  /* delay(20); */
  /* } */

  /* analogWrite(EN_A, 145); // Send PWM signal to L298N Enable pin */
  /* delay(2000); */
  /* analogWrite(EN_A, 145); */
  /* delay(2000); */
  /* analogWrite(EN_A, 0); */
  delay(500);
  /* _delay_ms(DELAY); */
}

void   back() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, HIGH);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, HIGH);
  delay(1000);
}

void   stop() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, LOW);
  delay(1000);
}

void   left() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, HIGH); // dreapta fata
  digitalWrite(in3, LOW);
  delay(500);
}

void   right() {
  digitalWrite(in1, HIGH); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, HIGH);
  delay(500);
}

void   obstacle(void) {
  stop();
  delay(1000);
  back();
stop();  
void (*f[])(void) = {left, right};
  f[rand()%2]();
  delay(1000);  
  /* back(); */
  delay(1000);
  stop();
}

void loop() {
  /* int potValue = analogRead(A0); // Read potentiometer value */
  /* int out = map(potValue, 0, 1023, 0 , 255); // Map the potentiometer value
   * from 0 to 255 */
  /* analogWrite(enA, pwmOutput); */
  
  delay(100); // 50                     // Wait 50ms between pings (about 20
              // pings/sec). 29ms should be the shortest delay between pings.

  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print
                                 // result (0 = outside set distance range)
  Serial.println("cm");



  int cm = sonar.ping_cm();
  /* if(cm) last = cm; */  
  /* if(!cm) cm = last; */

  /* distance(cm); */
  /* oneSensorCycle(cm); */

#if 0
switch (cm) {
	case 0: break;
	case 1 ... 10: digitalWrite(13, HIGH); break;
	default: digitalWrite(13, LOW); break; 
		
}

#endif
  /* void (*fp)(int, int) = digitalWrite; */

  /* if (cm == 0) fnull(); */

if(cm > 31) 
/* PINB |= 1<<5; */
	PORTB &= ~(1 << 5), ahead(); //obstacle(); //stop(), back(), left();
  /* digitalWrite(13, HIGH); */
else if (cm!=0)
  /* digitalWrite(13, LOW); */
	PORTB = (1 << 5), obstacle();
else
  fnull();


#if 0
  if(sonar.ping_cm() < 10 && sonar.ping_cm() > 1)
  	digitalWrite(13, HIGH);
  if (sonar.ping_cm() == 0) fnull();  
  else
  	digitalWrite(13, LOW);
#endif
}

void distance(int cm){
  Serial.print("Ping: ");
  /* Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print */
  Serial.print(cm); // Send ping, get distance in cm and print
                                 // result (0 = outside set distance range)
  Serial.println("cm");
}

void oneSensorCycle(
    int i) { // Sensor ping cycle complete, do something with the results.
  // The following code would be replaced with your code that does something
  // with the ping results.
  Serial.print(i);
  Serial.print("=");
  Serial.print("cm ");
  Serial.println();
}

void potentiometer() {
  Serial.print("Potentiometer value: ");
  Serial.print(analogRead(A0));
}

