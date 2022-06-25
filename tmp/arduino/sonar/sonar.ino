// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  
}

void fnull(){}

void loop() {
  delay(100); //50                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  //digitalWrite(13, HIGH);
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

int cm = sonar.ping_cm();  

#if 0
switch (cm) {
	case 0: break;
	case 1 ... 10: digitalWrite(13, HIGH); break;
	default: digitalWrite(13, LOW); break; 
		
}

#endif
void (*fp)(int, int) = digitalWrite;

if (cm == 0) fnull();

if(16 > cm && cm > 1) 
  digitalWrite(13, HIGH);
else
  digitalWrite(13, LOW);

#if 0
  if(sonar.ping_cm() < 10 && sonar.ping_cm() > 1)
  	digitalWrite(13, HIGH);
  if (sonar.ping_cm() == 0) fnull();  
  else
  	digitalWrite(13, LOW);
#endif
}

