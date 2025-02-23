#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
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
  Command(std::string name, std::string description, std::string syntax)
  {
    this->name = name;
    this->description = description;
    this->syntax = syntax;
  };

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

  virtual bool checkArguments(std::list<std::string> &args, int sizeRequired, std::string errorMessage)
  {
    if (args.size() < sizeRequired)
    {
      std::cout << errorMessage << std::endl;
      return true;
    }

    return false;
  }
};

#endif