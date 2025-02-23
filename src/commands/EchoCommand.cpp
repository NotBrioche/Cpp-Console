#include <iostream>
#include "Command.h"

class EchoCommand : public Command
{
public:
  EchoCommand()
  {
    this->name = "echo";
    this->description = "writes the first argument in the console";
    this->syntax = "echo [message]";
  };

  void execute(std::list<std::string> &args) override
  {
    std::cout << args.front() << std::endl;
  }
};