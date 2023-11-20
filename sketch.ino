//Group 9 Arduino Code
//Based on code from lastminuteengineers.com and thegeekpub.com

int resVal = 0;  //Sensor value
int resPin = A5; //Sensor pin

//Motor A connections
int enA = 13;
int in1 = 12;
int in2 = 11;

//Motor B connections
int enB = 0;
int in3 = 2;
int in4 = 1;

//Motor C connections
int enC = 9;
int in5 = 8;
int in6 = 7;

//Motor D connections
int enD = 3;
int in7 = 5;
int in8 = 4;

void setup() {
	//Initialise motor control pins to output
	pinMode(enA, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);

  pinMode(enB, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);

  pinMode(enC, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);

  pinMode(enD, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
	
	//Switch off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);

  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}

void loop() {
  //Take input
  resVal = analogRead(resPin);

  if (resVal >= 100) {
    //If water is detected
    //Move forward (sensor is on back, hence forward moves away from water)
    //For 1 second, then wait 1 second and move again if still wet
    forward();
    delay(1000);
  }
}

//Goes forward for 1 seconds
void forward() {
  //Set motor speed
	analogWrite(enA, 255);
	analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);

	//Turn on motors
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);

	digitalWrite(in3, HIGH);
	digitalWrite(in4, LOW);

  digitalWrite(in5, HIGH);
	digitalWrite(in6, LOW);

  digitalWrite(in7, HIGH);
	digitalWrite(in8, LOW);

  //Move forward for 1 second
	delay(1000);
	
	//Turn off motors
	digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);

	digitalWrite(in3, LOW);
	digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
	digitalWrite(in6, LOW);

  digitalWrite(in7, LOW);
	digitalWrite(in8, LOW);
}