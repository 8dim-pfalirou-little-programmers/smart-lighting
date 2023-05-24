


int IRSensor1 = 2; // connect ir sensor 1 to arduino pin 2
int IRSensor2 = 3; // connect ir sensor 2 to arduino pin 3
int IRSensor3 = 4; // connect ir sensor 2 to arduino pin 3
int LED1 = 13; // conect Led 1 to arduino pin 13
int LED2 = 12; // conect Led 2 to arduino pin 12
int LED3 = 11; // conect Led 3 to arduino pin 11
int LED4 = 10; // conect Led 4 to arduino pin 10
int LDR=A0;

void setup() 
{
Serial.begin(9600); 
  pinMode (IRSensor1, INPUT); // sensor pin INPUT
  pinMode (IRSensor2, INPUT); // sensor pin INPUT
  pinMode (IRSensor3, INPUT); // sensor pin INPUT
  pinMode (LED1, OUTPUT); // Led pin OUTPUT
  pinMode (LED2, OUTPUT); // Led pin OUTPUT
  pinMode (LED3, OUTPUT); // Led pin OUTPUT
  pinMode (LED4, OUTPUT); // Led pin OUTPUT
 }

void loop()
{
  int LDRValue = analogRead(LDR);

  Serial.println(LDRValue);

  delay (500);

  if (LDRValue<300){
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);
  int statusSensor3 = digitalRead (IRSensor3);
  
  Serial.println(statusSensor1);
    if (statusSensor1 == LOW){
    digitalWrite(LED1, HIGH); 
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW); 
    while (statusSensor2 ==HIGH){
    digitalWrite(LED1, HIGH); 
    digitalWrite(LED2, HIGH);
    statusSensor2 = digitalRead (IRSensor2);
    }
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW); 
    delay(10);
  }
  
    Serial.println(statusSensor2);
    if (statusSensor2 == LOW){
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, LOW); 
    while (statusSensor3 ==HIGH){
    digitalWrite(LED2, HIGH); 
    digitalWrite(LED3, HIGH);
    statusSensor3 = digitalRead (IRSensor3);
    }
    digitalWrite(LED2, LOW); 
    digitalWrite(LED3, LOW); 
    delay(10);
  }
 
    Serial.println(statusSensor3);
    
  if (statusSensor3 == LOW){
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW); 
    digitalWrite(LED3, HIGH); 
    digitalWrite(LED4, HIGH);
    
    delay(1000);
   }
  
  else
  {
    digitalWrite(LED1, LOW); 
    digitalWrite(LED2, LOW); 
    digitalWrite(LED3, LOW); 
    digitalWrite(LED4, LOW);
    
    delay(1);
  }  
  }  
}
