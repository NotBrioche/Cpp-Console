#include <iostream>
#include "Command.h"

class HelpCommand : public Command {
public:
  HelpCommand(std::list<Command*> commands) {
    this->name = "help";
    this->description = "display list of avalible commands";
    this->syntax = "help";
    this->commands = commands;
  }

  std::list<Command*> commands;

  void execute(std::list<std::string> &args) override
  {

    for (auto const &i : commands) {
      std::cout << i->getName() << " - " << i->getDescription() << std::endl;
    }
  }
};