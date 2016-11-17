/*
Arduino Turn LED On/Off using commands. 
It's a simple sketch which waits for a character on serial and in case of a desirable character, it turns an LED on/off.
Possible string values:
A (to turn the LED on)
B (to turn the LED off)
*/

char junk;
String inputString="";

void setup()                    // run once, when the sketch starts
{
 Serial.begin(9600);            // set the baud rate to 9600, same should be of your Serial Monitor
 pinMode(13, OUTPUT);
}

void loop()
{
  if(Serial.available()){
  while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { junk = Serial.read() ; }      // clear the serial buffer
    if(inputString == "A"){         //in case of 'A' turn the LED on
      digitalWrite(13, HIGH);  
    }else if(inputString == "B"){   //incase of 'B' turn the LED off
      digitalWrite(13, LOW);
    }
    inputString = "";
  }
}
