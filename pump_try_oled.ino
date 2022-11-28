/* u need to introduce your program for adafruit library which is adafruit SSD1306 IF IT IS WITH RESET PIN u need to change somethings in code
 *  i did a intelligent watering system it fully functions hope you like the code if u want something new made or new project ill put a link where to message me 
 */
#include <SPI.h>
#include <Wire.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_ADDR 0X3D
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
#define OLED_RESET    -1  // Reset pin # (or -1 if no reset pin if there is reset pin put 4 instead of -1)

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int In1=7;// introduce pump DIGITAL 7
int In2=8;// introduce pump DIGITAL 8
int ENA=5;// PIN 5
int PUMP=210;// POWER OF PUMP
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ; // to save sensor value
int moist;// to save sensor value for oled
void setup()
{
display.begin (SSD1306_SWITCHCAPVCC, 0x3C); 
display.clearDisplay ();
pinMode(In1,OUTPUT);// IN1 PIN set output
pinMode(In2,OUTPUT);// IN2 Pin set output
pinMode(ENA,OUTPUT);// Ena pin output

/* decide polarity set pin 1 "high" pin 2 "low"*/

digitalWrite(In1,HIGH);// TO CHANGE THE FLOW CHANGE IN1 HIGH TO LOW SAME FOR IN2
digitalWrite(In2,LOW);

analogWrite(ENA,PUMP);
//THE PUMP TAKES POWER BETWEEN 0 TO 225 THE HIGHER THE NUMBER THE MORE POWER/
     Serial.begin(9600); // to see the values so u can use them in output
   Serial.println("Reading From the Sensor ...");
   delay(2000);
 Serial.begin(9600); // for lcd
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) // if it is with reset put instead 0x3C Ox3D
  {
    Serial.println("SSD1306 allocation failed");
    while(1); //Don't proceed, loop forever
  }
  
 

}
  // put your main code here, to run repeatedly:

 void loop() {
     moist = map(output_value,550,10,0,100);// what values is reading for it to know
     moist = analogRead(sensor_pin);// from where to read
   output_value= analogRead(sensor_pin);// // from where to read
 output_value = map(output_value,550,10,0,100);// what values is reading for it to know
   Serial.print("Mositure : ");// to see the output in serial moniter in arduino program
   Serial.print(output_value);
   Serial.println("%");
display.clearDisplay();
display.setCursor(5, 0);
  display.println("Mo:"); //how it will display
  display.display();
   display.setCursor(60,0);
  display.print(moist);
  display.setCursor(110,0);
  display.print('%');
  display.setCursor(60,35);
    display.display();
  delay(2000);
   if(output_value<10)// change it to how much water u need ur plant to have
   {
      digitalWrite(In1,HIGH); // to tell the motor driver output which positive which is negative
      digitalWrite(In2,LOW);
     }
     else{
      digitalWrite(In1,LOW);
      digitalWrite(In2,LOW);
     }
   delay(1000);
}
