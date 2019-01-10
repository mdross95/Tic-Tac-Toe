#ifndef InputOutput_hpp
#define InputOutput_hpp

#include <iostream>
#include <string>
#include <vector>

//handles all i/o from/to program (for easy switching of UI)
class InputOutput
{
private:
    std::string promptMessage;
    std::string quitMessage;
    std::string quitString;
    std::string proceedMessage;
    
public:
    //constructors/destructors
    InputOutput();
    
    //initializers
    void initializeMessages();
    
    //getters/setters
    std::string getQuitString() const;
    
    //misc functions
    bool checkTerminate(std::string& in);
    
    template <class T> void send(T in)
    {
        std::cout << in;
    }
    
    template <class T> void sendLine(T in)
    {
        std::cout << in << std::endl << std::endl;
    }
    
    void proceed(); //prompt user to proceed
    void read(std::string& in);
    void think(int ms); //pause output to make it seem like AI is thinking
};

#endif /* InputOutput_hpp */
