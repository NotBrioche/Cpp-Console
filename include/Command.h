#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <list>

class Command
{
protected:
  std::string name;
  std::string description;
  std::string syntax;

public:
  Command() {};

  std::string getName()
  {
    return this->name;
  }

  std::string getDescription()
  {
    return this->description;
  }

  std::string getSyntax()
  {
    return this->syntax;
  }

  virtual void execute(std::list<std::string> &args) {};
};

#endif