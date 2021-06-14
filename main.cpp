#include <iostream>
#include <string.h>

class Tokenizer {
    private:
    int index = 0;
    int count = 0;

public:
    std::string stack[80];
    Tokenizer(char ( &msg )[]) {
        getTokens(msg);
        logger();
        parseTokens();
    }

    void engineFuncs(int frame){
        if (stack[frame] == "start"){
            startEngine();
        }
    }

    void uwbFuncs(int frame){
        if (stack[frame] == "start"){
            startUWB();
        }
    }

    void startEngine(){
        std::cout << "Starting Engine..." << std::endl;
    }

    void startUWB(){
        std::cout << "Starting Ultra Wide Band..." << std::endl;
    }

    void parseTokens(){
        std::string part;
        index = 0;
        while(index < sizeof(stack)){
            if(stack[index] == "engine"){
                index++;
                engineFuncs(index);
            }
            else if(stack[index] == "engine"){
                index++;
                uwbFuncs(index);
            }
            else if(stack[index] == ";"){
                index++;
            }
            else{
                std::cout << "Invalid input. Commands are written in a noun verb structure. ie noun: 'engine' verb: 'start'";
            }
        }
    }

    void logger(){
        std::cout << "Stack: " << std::endl;
        for (int i = 0; i < count; i++)
            std::cout << stack[i] << std::endl;
    }

    void addToStack(std::string ( &str )){
        stack[count] = str;
        index++;
        count++;
        str.clear();
    }

    void advance(std::string ( &str ), char ( &c )){
        str+= c;
        index++;
    }

    void getTokens(char ( &msg )[]){
        std::string str;
        char c = msg[index];
        while(index < strlen(msg) +1) {
            if (isspace(c)) {
                skipWhitespace(msg);
                addToStack(str);
                c = msg[index];
            }
            else if(c == '\0') {
                addToStack(str);
            }
            else {
                advance(str, c);
                c = msg[index];
            }
        }
    }

    char peek(char ( &msg )[]){
        char peekValue = msg[index+1];
        return peekValue;
    }

    void skipWhitespace(char ( &msg )[]){
        while(isspace(peek(msg))) {
            index++;
        }
    }


};

int main() {
    char testString[] = "engine   start";
    Tokenizer toks(testString);
    return 0;
}
