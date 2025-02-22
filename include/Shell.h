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
  std::list<std::string> history;

  void executeCommand(const std::string &command);
  void saveCommand(std::string command);

  std::list<std::string> getParts(const std::string &command);
};

#endif