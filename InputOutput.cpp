#include "InputOutput.hpp"
#include <chrono>
#include <thread>

//constructors/destructors
InputOutput::InputOutput()
{
    initializeMessages();
}

//initializers
void InputOutput::initializeMessages()
{
    promptMessage = "Enter: ";
    quitString = "quit";
    quitMessage = "Exiting game. Thanks for playing!";
    proceedMessage = "Press enter to proceed.";
}

//getters/setters
std::string InputOutput::getQuitString() const
{
    return quitString;
}

//misc functions
void InputOutput::proceed()
{
    sendLine(proceedMessage);
    std::string anyKey;
    read(anyKey);
}

void InputOutput::read(std::string& in)
{
    send(promptMessage);
    getline(std::cin, in);
    
    if (checkTerminate(in))
    {
        send("\n");
        sendLine(quitMessage);
        exit(0);
    }
    
    send("\n");
}

bool InputOutput::checkTerminate(std::string& in)
{
    return (in == quitString);
}

void InputOutput::think(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
