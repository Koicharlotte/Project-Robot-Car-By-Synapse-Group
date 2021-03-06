#define BLYNK_PRINT Serial 
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define RightMotorSpeed 5 // D1 <-> IN1
#define RightMotorDir 0  // D3 <-> IN2
#define LeftMotorSpeed 4  // D2 <-> IN3
#define LeftMotorDir 2  // D4 <-> IN4

char auth[] = "i9BZoJGzTn0ggDd4dHo4jXtdbTAV3ZXH";
char ssid[] = "Charlotte_2.4";
char pass[] = "1427050344";

void setup()
{
 Serial.begin(9600);
 Blynk.begin(auth, ssid, pass);

 pinMode(RightMotorSpeed, OUTPUT);
 pinMode(RightMotorDir, OUTPUT);
 pinMode(LeftMotorSpeed, OUTPUT);
 pinMode(LeftMotorDir, OUTPUT);
}

void loop()
{
 Blynk.run();
}

void halt()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, HIGH);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, HIGH);
}

void forward()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, LOW);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, LOW);
}

void reverse()
{
 digitalWrite(RightMotorDir, LOW);
 digitalWrite(LeftMotorDir, HIGH);
 digitalWrite(RightMotorSpeed, LOW);
 digitalWrite(LeftMotorSpeed, HIGH);
}

void right()
{
 digitalWrite(RightMotorDir, LOW);
 digitalWrite(LeftMotorDir, HIGH);
 digitalWrite(RightMotorSpeed, HIGH);
 digitalWrite(LeftMotorSpeed, LOW);
}

void left()
{
 digitalWrite(RightMotorDir, HIGH);
 digitalWrite(LeftMotorDir, LOW);
 digitalWrite(RightMotorSpeed, LOW);
 digitalWrite(LeftMotorSpeed, HIGH);
}

BLYNK_WRITE(V0)
{
 if (param[0])
 forward();
 else
 halt();
}

BLYNK_WRITE(V1)
{
 if (param[0])
 reverse();
 else
 halt();
}

BLYNK_WRITE(V2)
{
 if (param[0])
 right();
 else
 halt();
}

BLYNK_WRITE(V3)
{
 if (param[0])
 left();
 else
 halt();
}
