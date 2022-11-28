int In1=7;// introduce pump DIGITAL 7
int In2=8;// introduce pump DIGITAL 8
int ENA=5;// PIN 5
int PUMP=210;// POWER OF PUMP
int sensor_pin = A0; // Soil Sensor input at Analog PIN A0
int output_value ;
void setup()
{
pinMode(In1,OUTPUT);// IN1 PIN set output
pinMode(In2,OUTPUT);// IN2 Pin set output
pinMode(ENA,OUTPUT);// Ena pin output

/** decide polarity set pin 1 "high" pin 2 "low"**/

digitalWrite(In1,HIGH);/*TO CHANGE THE FLOW CHANGE IN1 HIGH TO LOW SAME FOR IN2*/
digitalWrite(In2,LOW);

analogWrite(ENA,PUMP);
/*THE PUMP TAKES POWERE BETWEEN 0 TO 225 THE HIGHER THE NUMBER THE MORE POWER*/
  pinMode(In1,OUTPUT);
     Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
   delay(2000);
}
  void loop() {
   output_value= analogRead(sensor_pin);
 output_value = map(output_value,550,10,0,100);
   Serial.print("Mositure : ");
   Serial.print(output_value);
   Serial.println("%");
   if(output_value<0){
      digitalWrite(In1,HIGH);
      digitalWrite(In2,LOW);
     }
     else{
      digitalWrite(In1,LOW);
      digitalWrite(In2,LOW);
     }
   delay(1000);
}
