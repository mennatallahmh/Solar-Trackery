#include <Servo.h>
//defining Servos
Servo servohori;
int servoh = 0;
int servohLimitHigh = 160;
int servohLimitLow = 20;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 160;
int servovLimitLow = 20;
//Assigning LDRs
int ldrtopl = A2; //top left LDR green
int ldrtopr = A1; //top right LDR yellow
int ldrbotl = A3; // bottom left LDR blue
int ldrbotr = A0; // bottom right LDR orange

 void setup () 
 {
  Serial.begin(9600);
  servohori.attach(A5);
  servohori.write(0);
  servoverti.attach(A4);
  pinMode(ldrtopl,INPUT);
  pinMode(ldrtopr,INPUT);
  pinMode(ldrbotl,INPUT);
  pinMode(ldrbotr,INPUT);
 servoverti.write(90);
  delay(500);
  
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  //capturing analog values of each LDR
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
    int botr = analogRead(ldrbotr);
  // calculating average
  int avgtop = (topl + topr) / 2; //average of top LDRs
  int avgbot = (botl + botr) / 2; //average of bottom LDRs
  int avgleft = (topl + botl) / 2; //average of left LDRs
  int avgright = (topr + botr) / 2; //average of right LDRs
Serial.print(" Average Left = ");
Serial.println(avgleft);
Serial.print(" Average right = ");
Serial.println(avgright);

Serial.println("________________________");



  if (avgtop < avgbot)
  {
    servoverti.write(130);
  
    delay(1000);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(80);
 
    delay(1000);
  }
  
if(avgleft>avgright)
{
  servohori.write(60);

delay(1000);
  }
  else if (avgleft<avgright)
  {
    
  servohori.write(150);
delay(1000);
  }  
  
  delay(500);  
}
