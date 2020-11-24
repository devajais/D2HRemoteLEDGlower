#include <IRremote.h>

int IRpin = 12;
IRrecv irrecv(IRpin);
decode_results results;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(7,OUTPUT);
  
  pinMode(4,OUTPUT);
  pinMode(9,OUTPUT);
  
  // Start the receiver
}  
void loop() 

{   
  if (irrecv.decode(&results)) // decode the IR signal from remote
    {
     Serial.println(results.value); // Print the Serial 'results.value'
      delay(10);

     irrecv.resume();

     // in my videocon remote, there are two IR signals for each button so i need to decode the radiation and check the both IR signal
     // already decoded my button IR radiation and checking the conditions that they are true or not. If true then Led glows for the particular button 
     if ((results.value==6308) || (results.value==2212)) // for Button 1
     {
      ab();
     }
     if ((results.value==6306) || (results.value==2210)) // for Button 2
     { 
      aa();
     }
     if ((results.value==6311) || (results.value==2215)) //for Button 3
     { 
      ac();
     }
     
     // Receive the next value
    }
}    
// with these function, the led glows only when TSOP1838b recieves correct IR signal that is in condtional statements. 
void aa() // When Button 2 pressed LED on 7th pin glows
{
  digitalWrite(7,HIGH);
     delay(500);
     digitalWrite(7,LOW);
}
void ac() // When Button 3 pressed LED on 9th pin glows
{
  digitalWrite(9,HIGH);
     delay(500);
     digitalWrite(9,LOW);
}
void ab() // When Button 1 pressed LED on 4th pin glows
{
   digitalWrite(4,HIGH);
     delay(500);
     digitalWrite(4,LOW);

} 
