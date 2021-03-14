/*
 * ****ALWAYS REMOVE THE BATTERY FROM THE BOT BEFORE CONNECTING IT TO YOUT PC.*****
 * Video tutorial:- https://www.youtube.com/channel/UCe5G9yS2XvetGfjfT-O89vw
 * Ask for help on discord:- https://discord.gg/fMXvGty
 * Downlaod stl files for robot from here:-https://www.thingiverse.com/thing:2662828
 */
#include <AFMotor.h>  //Adafruit Motor drive library might need to install.
#include <SoftwareSerial.h> //To declare new RX-TX pins
SoftwareSerial mySerial(9, 10);// RX, TX  // RX-pin on bluetooth goes to Servo_1 on motor driver and TX pin goes to servo_2
AF_DCMotor motor3(3); //Motor slot M3 on the board
AF_DCMotor motor4(4); //Motor slor M4 on the board
char bt='S';
void setup()
{  
  Serial.begin(9600);  //start serial communication through USB serial. 
  mySerial.begin(9600);// start serial communication using bluetooth.
  motor3.setSpeed(250);//Set the speed of motor 0 is lowest 255 is maximum.
  motor4.setSpeed(250); // For some motors lower value might not work so you have to do lots of trial and error to find the sweet spot.
}
void loop() {
bt=mySerial.read(); // Read in coming data from the phone app.
if(bt=='f'|| bt=='F')
{
 forward(); 
}
if(bt=='b'|| bt=='B')
{
 backward(); 
}
if(bt=='L'|| bt=='l')
{
 left(); 
}
if(bt=='R'|| bt=='r')
{
 right(); 
}
if(bt=='S')
{
 Stop(); 
}
if(bt=='j'||bt=='J')
{
 Stop(); 
}
}
void forward()
{
  Serial.print("fwd");
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}

void backward()
{
  Serial.print("back");
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}
void left()
{
  Serial.print("left");
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}
void right()
{
  Serial.print("right");
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}
void Stop()
{
  Serial.print(" All motor stopped");
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
