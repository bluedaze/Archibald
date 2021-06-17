#include <Wire.h>
char buf[80];
char emptyString='\0';

int readline(int readch, char *buffer, int len){
  static int pos = 0;
  int rpos;

  if (readch > 0){
    switch (readch){
      case '\r': // ignore CR
        break;
      case '\n':
        rpos = pos;
        pos = 0; // reset position index ready for next time
        return rpos;
      default:
        if (pos < len-1){
          buffer[pos++] = readch;
          buffer[pos] = 0;
        }
    }
  }
  return 0;
}
  
void setup() 
{
  Wire.begin();
  Serial.begin(9600);
}

void createTransmission(char* message){
    Wire.beginTransmission(9);
    Wire.write(message);
  }

void loop() {
    if(readline(Serial.read(), buf, 80) > 0){
      Serial.print("You entered: >");
      Serial.print(buf);
      Serial.println("<");
      createTransmission(buf);
      Wire.endTransmission();
      char buf = emptyString;
  }
}
