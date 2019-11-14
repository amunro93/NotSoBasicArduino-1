#include <Servo.h>
int trigpin = 11;
int echopin = 12;
long duration, cm, inches;
Servo myservo;
void setup()
{
	myservo.attach(5);
	Serial.begin(9600);
	pinMode(trigpin, OUTPUT);
	pinMode(echopin, INPUT);
}

void loop()
{
	servo();
	print();
}

int getdistance() //This is the setup of a function . It allows the user to reuse code easily.
{
	digitalWrite(trigpin, LOW)// 
	delayMicroseconds(5);// 5 microseconds delay 
	digitalWrite(trigpin, HIGH);
	delayMicroseconds(10);// 10 microseconds delay 
	digitalWrite(trigpin, LOW);
	pinMode(echopin, INPUT);
	duration = pulseIn(echopin, HIGH);
	cm = (duration/2) / 29.1;
	inches = (duration/2) / 74;
	return inches;
}

void servo()
{
	inches = getdistance();// makes "inches" equal to what is returned from getdistance.
	
	if (inches < 10) // if it's less than 10 inches then servo stop 
	{
		myservo.write(90);
	}
	if (inches > 10)
	{
		myservo.write(180);
	}
}

void print()
{
	Serial.print(inches);
	Serial.print("in, ");
	Serial.print(cm);
	Serial.print("cm");
	Serial.println();
	delay(250);
}
