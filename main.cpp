#include <Wire.h>
int GREEN = 2;
int RED = 3;
int E1 = 5;     //M1 Speed Control
int E2 = 6;     //M2 Speed Control
int M1 = 4;    //M1 Direction Control
int M2 = 7;    //M1 Direction Control
char messageBuffer[80];
struct stackdef {
    String tokens[80];
};



class Parser {
  public:
    int tokens;
    stackdef msg;
    int index = 0;

    Parser(stackdef &msg, int tokens) {
        this-> msg = msg;
        this-> tokens = tokens;
        parseTokens();
    }


    void startEngine(char a) {
        Serial.println("Starting engine");
        analogWrite(E1, a);  //  PWM Speed Control
        analogWrite(E2, a);  //  PWM Speed Control
        digitalWrite(M1, HIGH);
        digitalWrite(M2, HIGH);
    }

    void turnRight (char a, char b)             //Turn Right
    {
        analogWrite (E1, a);
        digitalWrite(M1, HIGH);
        analogWrite (E2, b);
        digitalWrite(M2, LOW);
    }

    void turnLeft (char a, char b)             //Turn Right
    {
        analogWrite (E1, a);
        digitalWrite(M1, LOW);
        analogWrite (E2, b);
        digitalWrite(M2, HIGH);
    }

    void stopEngine(void) {
        Serial.println("Stopping Engine");
        digitalWrite(E1, LOW);
        digitalWrite(E2, LOW);
    }

    void uwbFuncs() {
        if (msg.tokens[index] == "start") {
            startUWB();
            index++;
        }
        else if (msg.tokens[index] == "stop") {
            stopUWB();
            index++;
        }
    }

    void startUWB() {
        Serial.println("Starting Ultra Wide Band...");
    }

    void stopUWB() {
        Serial.println("Stopping Ultra Wide Band...");
    }

    
    void reverse (char a, char b)          //Move backward
    {
      analogWrite (E1, a);
      digitalWrite(M1, LOW);
      analogWrite (E2, b);
      digitalWrite(M2, LOW);
    }

    void engineFuncs() {
        if (msg.tokens[index] == "start") {
            startEngine(255);
            index++;
        } else if (msg.tokens[index] == "stop") {
            stopEngine();
            index++;
        } else if (msg.tokens[index] == "right"){
            turnRight(250, 250);
            index++;
        } else if(msg.tokens[index] == "reverse"){
            reverse(250, 250);
            index++;
        } else if(msg.tokens[index] == "left"){
            turnLeft(250, 250);
            index++;
        }
    }

    void parseTokens() {
        while (index < tokens) {
            if (msg.tokens[index] == "engine") {
                index++;
                engineFuncs();
            } else if (msg.tokens[index] == "uwb") {
                index++;
                uwbFuncs();
            } else if (msg.tokens[index] == ";") {
                index++;
            } else {
                Serial.println("Invalid input. "
                "Commands are written in a noun verb structure."
                "ie noun: 'engine' verb: 'start'");
                index++;
                break;
            }
        }
    }
};


class Tokenizer {
  public:
    int index = 0;
    int count = 0;

    stackdef message;
    char* msg;

    Tokenizer(char msg[]) {
        this -> msg = msg;
        getTokens();
    }

    void addToStack(String &str) {
        message.tokens[index] = str;
        index++;
        count++;
        str = "";
    }

    void advance(String &str, char c ) {
        str+= c;
        count++;
    }

    void getTokens() {
        String str = "";
        char c = msg[count];
        while (count < strlen(msg) +1) {
            if (isspace(c)) {
                skipWhitespace();
                addToStack(str);
                c = msg[count];
            } else if (c == '\0') {
                addToStack(str);
            } else {
                advance(str, c);
                c = msg[count];
            }
        }
    }

    char peek() {
        char peekValue = msg[count+1];
        return peekValue;
    }

    void skipWhitespace() {
        while (isspace(peek())) {
            count++;
        }
    }
};


void receiveEvent(int howMany) {
    byte index = 0;

    while  (Wire.available() && (index < 80)){  //  Make sure that only a max of 80 bytes are read {
        messageBuffer[index++] = Wire.read();  //  Read one byte to index and increment (++) index
    }
    Tokenizer tokens(messageBuffer);
    Parser parser(tokens.message, tokens.index);
    memset(messageBuffer, 0, sizeof(messageBuffer));
}



void setup() {
    Serial.begin(115200);
    Wire.begin(9);
    Wire.onReceive(receiveEvent);
}

void loop() {
  }
  
