#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <list>

#include "Command.h"

class Shell
{
public:
  Shell() {};
  void run();

  std::list<Command *> commands;
  void executeCommand(const std::string &command);
};

#endif