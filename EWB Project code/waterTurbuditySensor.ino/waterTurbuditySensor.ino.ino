/*
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 *
 **/

#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#define interval 4
#define hrs 12
#define mms 15

byte ledRedPin = 12;                // Connect an RED LED on pin 9, or use the onboard one
byte ledYellowPin = 10;                 // Connect an Amber LED on pin 10, or use the onboard one
byte ledGreenPin = 8 ;                // Connect an Green LED on pin 11, or use the onboard one
byte sensor_in = A0;

int dailylogger[hrs][mms];
float secondlogger=0;

const char* months[] =
{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};

// Initializes all values:
byte ss = 0;
byte mm = 0;
byte hh = 0;
byte dd = 0;
byte mth = 0;
byte y = 0;
int k;
void setup()  {
	for (int i = 0; i < hrs; i++ ){
		for (int j = 0; j < mms; j++ ){
			dailylogger[i][j] = -1;
		}
	}

	Serial.begin(9600);

	pinMode(sensor_in, INPUT);       //Set the turbidity sensor pin to input mode
	pinMode(ledRedPin, OUTPUT);      // Set ledPin to output mode
	pinMode(ledYellowPin, OUTPUT);      // Set ledPin to output mode
	pinMode(ledGreenPin, OUTPUT);      // Set ledPin to output mode

	Serial.println("#################################");
	Serial.println("Enter f to fetch data in logger\n");

	Serial.println("Please change to newline settings on\nthe lower right of the Serial Monitor\n");
	Serial.println("and set the date and time now:");
	Serial.println("#################################");

	// This set of functions allows the
	// user to change the date and time

	setTime();
	digitalClockDisplay();
	if(timeStatus()!= 1) {
		Serial.println(timeStatus());
		Serial.println("Unable to sync with the RTC");
		while(true);
	}else{
		Serial.println();

		Serial.println("RTC has set the system time");
		Serial.print("The current date and time is now: ");
		digitalClockDisplay();

		Serial.println();
	}

	k=0;
}
void loop(){
	char incomingByte = 0;

	// Read the oldest byte in the serial buffer:
	incomingByte = Serial.read();
	if ( incomingByte == 'f' ) {
		fetchData();
	}
	int sensorValue = analogRead(sensor_in);// read the input on analog pin 0:
	float v = sensorValue * (5000 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
	//float n);
	v=v/1000;
	float ntu = (4.3 - v)/0.00199;
	if(k < interval*60) {
		secondlogger += ntu;
		k++;
	}

	if(k == interval*60) {
		dailylogger[hh][(mm/interval)] = int((secondlogger/k)*10);

		Serial.print("average of last 4 mins NTU:");
		Serial.println(dailylogger[hh][(mm/interval)]/10.0);
		secondlogger = 0;
		k = 0;
		Serial.println();

	}
	if (timeStatus() == 1 ) {
		Serial.print("live NTU value: ");
		Serial.print(ntu); // print out the value you read:
		Serial.print(" ");
		Serial.print("\t");
		digitalClockDisplay();

	} else {
		Serial.println("The time has not been set.  Please run the Time");
		Serial.println("TimeRTCSet example, or DS1307RTC SetTime example.");
		Serial.println();
		delay(4000);

	}


	if(ntu > 10){    //read sensor signal
		red_light();   // turn on red
	}else if (ntu <= 10 && ntu >= 6) {
		yellow_light();// turn on yellow light

	}else if (ntu < 5) {
		green_light(); // turn on green light

	}

	delay(1000);
}
void green_light() {
	digitalWrite(ledGreenPin, HIGH);
	digitalWrite(ledYellowPin,LOW);
	digitalWrite(ledRedPin, LOW);

}

void yellow_light() {
	digitalWrite(ledGreenPin,LOW);
	digitalWrite(ledYellowPin,HIGH);
	digitalWrite(ledRedPin,LOW);
}


void red_light() {
	digitalWrite(ledGreenPin, LOW);
	digitalWrite(ledYellowPin, LOW);
	digitalWrite(ledRedPin,HIGH);
}


// This set of codes is allows input of data
void setTime() {
	Serial.print("Please enter the current year, 00-99. - ");
	y= readByte();
	Serial.println(y);
	Serial.print("Please enter the current month, 1-12. - ");
	mth = readByte();
	Serial.println(months[mth-1]);
	Serial.print("Please enter the current date, 1-31. - ");
	dd = readByte();
	Serial.println(dd);
	Serial.print("Please enter the current hour in 24hr format, 0-23. - ");
	hh = readByte();
	Serial.println(hh);
	Serial.print("Please enter the current minute, 0-59. - ");
	mm = readByte();
	Serial.println(mm);
	Serial.print("Please enter the current second, 0-59. - ");
	ss = readByte();
	Serial.println(ss);

	Serial.print("The data has been entered.");
	setTime(hh,mm,ss,dd,mth,y);
	setSyncProvider(RTC.get);   // the function to get the time from the RTC

}


byte readByte() {
	while (!Serial.available()) delay(10);
	byte reading = 0;
	byte incomingByte = Serial.read();
	while (incomingByte != '\n') {
		if (incomingByte >= '0' && incomingByte <= '9')
			reading = reading * 10 + (incomingByte - '0');
		else;
		incomingByte = Serial.read();
	}
	Serial.flush();
	return reading;

}

void digitalClockDisplay(){
	//    digital clock display of the time

	Serial.print(hour());
	printDigits(minute());
	printDigits(second());
	Serial.print(" ");
	Serial.print(day());
	Serial.print("/");
	Serial.print(months[month()-1]);
	Serial.print("/");
	Serial.print(year());
	Serial.println();
	ss = second();
	mm = minute();
	if(hour() < 12) {
		hh = hour();
	} else {
		hh = hour() - 12;
	}

}

void printDigits(int digits){
	// utility function for digital clock display: prints preceding colon
	// and leading 0
	Serial.print(":");
	if(digits < 10)
		Serial.print('0');
	Serial.print(digits);
}
void fetchData(){
	for ( int i = 0; i < mms; i++ ){
		Serial.print('\t');
		Serial.print(interval*i);
	}
	Serial.println();

	for (int i = 0; i < hrs; i++ ){
		if(isPM() && i == 0){
			Serial.print(12);
		} else {
			Serial.print(i);
		}
		Serial.print(":00\t");
		for (int j = 0; j < mms; j++ ){
			Serial.print(dailylogger[i][j]/10.0);
			Serial.print('\t');
		}
		Serial.println();
	}
}

