//Pins
const int trigPin = 0;
const int echoPin = 1;
int relay1 = 2;
int relay2 = 3;

//Relay
volatile byte relayState = LOW;

// Variables
long duration;
int distance;

void setup() {
	Serial.begin(9600);
	pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
	pinMode(echoPin, INPUT); // Sets the echoPin as an Input
	for (int i = 1; i <= 6; i++)
	{
		pinMode(i, OUTPUT);
	}
	pinMode(3, OUTPUT);
	pinMode(relay1, OUTPUT);
	digitalWrite(relay1, HIGH);
	pinMode(relay2, OUTPUT);
	digitalWrite(relay2, HIGH);

}
void loop() {
	// Clear trigPin
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);

	// Set trigPin on HIGH state for 10 micro seconds
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	// Read echoPin, returns the sound wave travel time in microseconds
	duration = pulseIn(echoPin, HIGH);

	// Calculating the distance
	distance = duration * 0.034 / 2;

	// Prints the distance on the Serial Monitor
	Serial.print("Distance: ");
	Serial.println(distance);

	if (distance <= 200)
	{
		digitalWrite(relay2, LOW); // Turns ON Relay 1
	}

	delay(50);

	if (distance >= 250)
	{
		digitalWrite(relay2, HIGH); // Turns Relay Off 
	}

	if (distance <= 2)
	{
		digitalWrite(relay1, LOW); // Turns ON Relay 1
	}

	delay(50);

	if (distance >= 10)
	{
		digitalWrite(relay1, HIGH); // Turns Relay Off 
	}
	//if (distance = 0)
	{
		// Trigger fault alarm
	}
}