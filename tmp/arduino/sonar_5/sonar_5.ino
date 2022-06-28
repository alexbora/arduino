// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------


#define TRIGGER_PIN 8
#define ECHO_PIN 7 
#define MAX_DISTANCE 400 

#define DELAY 500



int EN_A = 9; // 4
int in1 = 2;  // stanga
int in2 = 3;

int EN_B = 10; // 3 // 10
int in3 = 4;   // dreapta
int in4 = 5;



static void setup() {
  pinMode(13, OUTPUT);

  /* pinMode(EN_A, OUTPUT); */
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  /* pinMode(EN_B, OUTPUT); */
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  /* analogWrite(EN_A, 255); */
  /* analogWrite(EN_B, 255); */
  Serial.begin(115200); 
}


static inline void ahead() {


  for (int i = 0; i < 256; i++) {
{  analogWrite(9, i); //ENA pin
  analogWrite(10, i); //ENB pin
}


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
  delay(DELAY);
  /* _delay_ms(DELAY); */
}

static inline void   back() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, HIGH);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, HIGH);
  delay(DELAY * 2);
}

static inline void   stop() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, LOW);
  delay(DELAY * 2);
}

static inline void   left() {
  digitalWrite(in1, LOW); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, HIGH); // dreapta fata
  digitalWrite(in3, LOW);
  delay(DELAY);
}

static inline void right() {
  digitalWrite(in1, HIGH); // stanga fata
  digitalWrite(in2, LOW);

  digitalWrite(in4, LOW); // dreapta fata
  digitalWrite(in3, HIGH);
  delay(DELAY);
}



static inline long microsecondsToCentimeters(long microseconds)
{
	return (microseconds / 29 / 2);
}



static inline long scanner()
{
	const int pingPin=8, EchoPin=7;
	long duration = 0;

	pinMode(pingPin, OUTPUT);
	pinMode(EchoPin, INPUT);  


	digitalWrite(pingPin, LOW);
	delayMicroseconds(2);
	digitalWrite(pingPin, HIGH);
	delayMicroseconds(2);  // Only 2uS NOT 10!
	digitalWrite(pingPin, LOW); 
	duration = pulseIn(EchoPin, HIGH);
	delay(100);

	return microsecondsToCentimeters(duration);
}


void loop() {
  
	delay(50);
 
	long cm = scanner();  

	if (cm > 35)
	{ 
		ahead(); PORTB &= ~(1 << 5);
	}
	else
	{
		stop(); back(); left(); stop(); PORTB =(1<<5);
	}

  /* Serial.print("Ping: "); */
  /* Serial.print(cm); */ 
  /* Serial.println("cm"); */
}
