#include "Command.h"

class ClearCommand : public Command
{
public:
  ClearCommand()
  {
    this->name = "clear";
    this->description = "Clears the console";
    this->syntax = "clear";
  };
  void execute() override
  {
    system("clear");
  };
};
