#include "Shell.h"
#include "ClearCommand.cpp"
#include "EchoCommand.cpp"

int main()
{

  ClearCommand clearCommand;
  EchoCommand echoCommand;

  Shell shell;

  shell.commands.push_back(&clearCommand);
  shell.commands.push_back(&echoCommand);

  shell.run();
  return 0;
}