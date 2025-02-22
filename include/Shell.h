#ifndef SHELL_H
#define SHELL_H

#include <string>

class Shell
{
public:
  Shell();
  void run();

  void executeCommand(const std::string &command);
};

#endif