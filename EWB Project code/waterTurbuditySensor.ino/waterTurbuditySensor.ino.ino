/*l
 * TimeRTC.pde
 * example code illustrating Time library with Real Time Clock.
 * 
 */

#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t

int ledRedPin = 9;                // Connect an RED LED on pin 9, or use the onboard one
int ledYellowPin = 10;                // Connect an Amber LED on pin 10, or use the onboard one
int ledGreenPin = 11;                // Connect an Green LED on pin 11, or use the onboard one
int sensor_in = A0;   

const char* days[] =
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char* months[] =
{"0","January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December"};
 
// Initializes all values: 
byte ss = 0;
byte mm = 0;
byte hh = 0;
byte dd = 0;
byte mth = 0;
byte y = 0;

void setup()  {
 
  //Wire.begin();
  Serial.begin(9600);
  
  pinMode(sensor_in, INPUT);       //Set the turbidity sensor pin to input mode
  pinMode(ledRedPin, OUTPUT);      // Set ledPin to output mode
  pinMode(ledYellowPin, OUTPUT);      // Set ledPin to output mode
  pinMode(ledGreenPin, OUTPUT);      // Set ledPin to output mode
  //delay(2000); // This delay allows the MCU to read the current date and time.
 
 
  Serial.println("Please change to newline ending the settings on the lower right of the Serial Monitor");
  Serial.println("and set the date and time now:");

    // This set of functions allows the user to change the date and time
    
    setTime();
    digitalClockDisplay();
      if(timeStatus()!= 1) {
        Serial.println(timeStatus());
        Serial.println("Unable to sync with the RTC");
        while(true);
      }else{
        Serial.println("RTC has set the system time");      
        Serial.print("The current date and time is now: ");
        digitalClockDisplay();
        Serial.println();
      }
 
 }

void loop(){
//  tu = map(sensorValue,2900,4750,2000,0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):

  int sensorValue = analogRead(sensor_in);// read the input on analog pin 0:
  float voltage = sensorValue * (5000 / 1024.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float n); 
  long n = map(voltage,0,5000,2000,0);
  float ntu = n/100.0;
  if(ntu > 10){       //read sensor signal 
      digitalWrite(ledRedPin, HIGH);   // if led is LOW, then turn on
      //tone(7, 50, 1000);
  }else if (ntu <= 6 && ntu >= 10) {
      //tone(7, 1500, 1000);
      digitalWrite(ledYellowPin, HIGH);    // if led is HIGH, then turn off the led
  }else if (ntu < 6) {
      tone(7,2000, 1000);
      digitalWrite(ledGreenPin, HIGH);    // if led is HIGH, then turn off the led
    
  }
  delay(1000);
  
  if (timeStatus() == 1 ) {
   /* Serial.print("Sensor value: ");
    Serial.print(sensorValue); // print out the value you read:
    Serial.print("Voltage value: ");
    Serial.print(voltage); // print out the value you read:
    */
    Serial.print("NTU value: ");
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
   delay(1000);
}
// This set of codes is allows input of data
void setTime() {
  Serial.print("Please enter the current year, 00-99. - ");
  y= readByte();
  Serial.println(y);
  Serial.print("Please enter the current month, 1-12. - ");
  mth = readByte();
  Serial.println(months[mth]);
  Serial.print("Please enter the current day of the month, 1-31. - ");
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
  // digital clock display of the time
  
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print("/");
  Serial.print(months[month()]);
  Serial.print("/");
  Serial.print(year()); 
  Serial.println(); 
  
}

void printDigits(int digits){
  // utility function for digital clock display: prints preceding colon and leading 0
  Serial.print(":");
  if(digits < 10)
    Serial.print('0');
  Serial.print(digits);
}

