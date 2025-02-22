#include "Shell.h"
#include "ClearCommand.cpp"

int main()
{

  ClearCommand clearCommand;

  Shell shell;

  shell.commands.push_back(&clearCommand);

  shell.run();
  return 0;
}