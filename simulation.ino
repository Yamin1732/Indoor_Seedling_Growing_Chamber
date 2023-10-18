#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);
int coolerFan=12;
int heaterFan=10;
int bulb=13;
int pump=9;


void setup(){
  lcd.begin(16,2); 
  pinMode(coolerFan,OUTPUT);
  pinMode(heaterFan,OUTPUT);
  pinMode(bulb,OUTPUT);
  pinMode(pump,OUTPUT);
  
}

void loop(){
  temperature();
  humidity();
  
}

void temperature(){
  float value= analogRead(A0);
  float mv= (value*5000)/1024;
  float temp=mv/10;
  lcd.setCursor(0,0);
  lcd.print("Temp= ");
  lcd.print(temp);
  lcd.print(char(223));
  delay(500);
  lcd.clear();
  if(temp>35)
  {
    digitalWrite(coolerFan,HIGH);
  }
  else
  {
    digitalWrite(coolerFan,LOW);
  }
  if(temp<28){
    digitalWrite(bulb,HIGH);
    digitalWrite(heaterFan,HIGH);
  }
  else{
    digitalWrite(bulb,LOW);
    digitalWrite(heaterFan,LOW);
  } 
}

void humidity() {

float soilSample= analogRead(A5);
lcd.setCursor(2,1);
lcd.print("Analog: ");
lcd.setCursor(11,1);
lcd.print(soilSample);
delay(500);
lcd.clear();
if(soilSample<871){
    digitalWrite(pump,HIGH);
  }
if(soilSample>963){
  digitalWrite(pump,LOW);
}
}

  

