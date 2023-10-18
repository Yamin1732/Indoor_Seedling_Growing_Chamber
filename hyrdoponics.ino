#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int Fan=12;
int bulb=13;
int pump=9;
int coolingFan=10;


void setup(){
 // lcd.begin(16,2); 
  pinMode(Fan,OUTPUT);
  pinMode(bulb,OUTPUT);
  pinMode(pump,OUTPUT);
  Serial.begin(9600);
  
}
void loop(){
  temperature();
  humidity();
}

void temperature(){
  float value= analogRead(A0);
  float mv= (value*5000)/1024;
  float temp=mv/10;
  //lcd.setCursor(0,0);
  Serial.print("Temp= ");
  Serial.print(temp);
  Serial.print("  ");
  delay(500);
  //Serial.clear();
  if(temp>35)
  {
    digitalWrite(Fan,HIGH);
  }

  else if(temp<25){
    digitalWrite(bulb,HIGH);
    digitalWrite(Fan,HIGH);
  }
  else
  {
    digitalWrite(bulb,LOW);
    digitalWrite(Fan,LOW);
  } 
}

void humidity() {
int moist;
int soilSample1= analogRead(A5);
int soilSample2= analogRead(A4);
int soilSample=(soilSample1+soilSample2)/2 ;                 
moist=map(soilSample,0,1023,100,0);
Serial.print("Moisture: ");
//Serial.setCursor(11,1);
Serial.print(moist);
Serial.println();
delay(500);
//Serial.clear();
if(moist<30){
    digitalWrite(pump,HIGH);
  }
if(moist>40){
  digitalWrite(pump,LOW);
}
}

  
