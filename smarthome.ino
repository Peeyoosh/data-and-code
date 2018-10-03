#include <DHT.h>

#include <Adafruit_Sensor.h>
#define DHTPIN 2
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}
float hum;
float temp;
int people=0;
int in=0;
int photocell=0;
int c=0;
void loop() {
  // put your main code here, to run repeatedly:
  temp= dht.readTemperature();
  photocell = (analogRead(0)/4);
  Serial.print(photocell);
  Serial.print("  ");
  Serial.print(temp);
  Serial.print("    ");
  if (digitalRead(6) == HIGH){
  if (digitalRead(6) == HIGH) {
    Serial.print("Active    ");
    if(digitalRead(7)== HIGH){
      Serial.print("Active");
      while(digitalRead(7)==HIGH){
        if(photocell<50){
        digitalWrite(LED_BUILTIN, HIGH);
        }
        c=c+1;
      }
      Serial.print("  LED ON  ");
      c=0;
      digitalWrite(LED_BUILTIN, LOW);
      people=people+1;
    }
    else{
      Serial.print("InActive");
    }
  }
  else {
    Serial.print("Inactive");
    if(digitalRead(7) == LOW){
      Serial.print("  InActive");
      digitalWrite(LED_BUILTIN, LOW);
    }
    else{
      Serial.print("  Active");
      if(photocell<50)
      while(digitalRead(7)==HIGH){
        digitalWrite(LED_BUILTIN, HIGH);
        c=c+1;
      }
      Serial.print("  LED ON  ");
      c=0;
      digitalWrite(LED_BUILTIN, LOW);
    }

    

  
  }
  }
else{
  if (digitalRead(7) == HIGH) {
    Serial.print("Active    ");
    if(digitalRead(6)== HIGH){
      Serial.print("Active");
      while(digitalRead(7)==HIGH){
        digitalWrite(LED_BUILTIN, HIGH);
        Serial.print("  LED ON  ");
      }
      digitalWrite(LED_BUILTIN, LOW);
      people=people-1;
    }
    else{
      Serial.print("InActive");
    }
  }
  else {
    Serial.print("Inactive");
    if(digitalRead(7) == LOW){
      Serial.print("  InActive");
      digitalWrite(LED_BUILTIN, LOW);
    }
    else{
      Serial.print("  Active");
      while(digitalRead(7)==HIGH){
        digitalWrite(LED_BUILTIN, HIGH);
        c=c+1;
      }
      Serial.print("  LED ON  ");
      c=0;
      digitalWrite(LED_BUILTIN, LOW);
  }
}
  Serial.print("  ");
  Serial.print(people);
  
    
    
  Serial.println("");
  delay(1000);
 /* if (digitalRead(7) == HIGH) {
    Serial.println("Active");
    if(digitalRead(6)== HIGH){
      people=people-1;
    }
  }
  else {
    Serial.println("Inactive");
  }
  
  


  if(people){
    Serial.print("the temperature of the house is : "); 
    Serial.println(temp);
    if(temp<12){
      //trun on the motor in clockwise direction
    }
    else if( temp>22){
      //turn motor in anti clock wise direction
    
    }
    else{
      // trun motor in anticlockwise direction
    }
    
    if(temp>22){
      //trun on the motor in clockwise direction
    }
    else if( temp>22){
      //turn motor in anti clock wise direction
    
    }
    else{
      // trun motor in anticlockwise direction
    }
  }
  else{
    //trun off all the motor and electric devices that is used to either increase or decrease the temperatue of the house
  }
*/
}
}
