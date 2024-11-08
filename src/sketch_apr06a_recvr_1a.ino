#include <RH_ASK.h>
#include <SPI.h> //Serial peripheral interface library


RH_ASK rf_driver;

String accel;
String gyro;
String str_out;

int ax, ay; // create the variables for storing int values of string(accel) and string(gyro)

 int M1 =3;
 int M2 =4;
 int M3 =5;
 int M4 =6;
int ENA = 9;  //PWM pins of arduino pro mini or most of the Arduino
int ENB = 10;

void setup() 
{
  rf_driver.init();
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

}

void loop() 
{
  int buf[7];  // mention the size of the data... depends on how much data is sent. In this case [7].
  uint8_t buflen = sizeof(buf); // store the whole data ...depends on the user .. if you want you can store  specific part of data.
  if(rf_driver.recv(buf, &buflen))
   {
    str_out = String((char*)buf); //Again recover and seperate the values which were combined in the transmitter program.
    
      for(int i=0; i<str_out.length(); i++)
      {
        if(str_out.substring(i,i+1)==",")
          {
            accel =str_out.substring(i);  // create seperate substrings to store the values of accel and gyro
            break;
          }
    Serial.print("X:");  //Print the values
    Serial.println(accel);
    Serial.print("Y:");
    Serial.println(gyro);
      
      }
   }

    ay= accel.toInt(); //Convert the Received string values to Int values.
    
    
     if(( ax > 7.94 && ax<8.32 && ay>2.47 &&ay<3.52 )) // Create setpoints ....depends on MPU to MPU you have to set these manually ..dont copy the values may wont work in your case.
     {
      analogWrite(ENA, 255); //Forward
      analogWrite(ENB, 255);
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      digitalWrite(M3, HIGH);
      digitalWrite(M4, LOW);
     }
     else if(ax >-5.66 && ax<-5.44 && ay>-0.06 && ay< 0.14)
     {
      analogWrite(ENA, 255 ); //Backward
      analogWrite(ENB, 255 );
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      digitalWrite(M3, LOW);
      digitalWrite(M4, HIGH);
     }
     else if(ay<-8.71 && ay>-8.40 &&ax>1.30 && ax<1.72) 
      {
       analogWrite(ENA,255); //Right
      analogWrite(ENB, 255);
      digitalWrite(M1, LOW);
      digitalWrite(M2, HIGH);
      digitalWrite(M3, HIGH);
      digitalWrite(M4, LOW);
      }
     else if( ay>8.42 && ay<8.74 &&ax>2.50 &&ax<2.77)
      {
       analogWrite(ENA, 255); //Left
      analogWrite(ENB, 255);
      digitalWrite(M1, HIGH);
      digitalWrite(M2, LOW);
      digitalWrite(M3, LOW);
      digitalWrite(M4, HIGH);
      }

     else 
     {
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
     }
}  
