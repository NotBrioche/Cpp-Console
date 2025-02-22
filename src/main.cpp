#include "Shell.h"

// Include commands
#include "ClearCommand.cpp"
#include "EchoCommand.cpp"
#include "HelpCommand.cpp"

int main()
{

  ClearCommand clearCommand;
  EchoCommand echoCommand;

  Shell shell;

  // Add commands to the shell
  shell.commands.push_back(&clearCommand);
  shell.commands.push_back(&echoCommand);

  // Prepare hard coded commands for the help command
  std::list<Command *> helpCommands = shell.commands;
  Command exit("exit", "exits the shell", "exit");
  Command help("help", "display the list of commands", "help");
  helpCommands.push_back(&exit);
  helpCommands.push_back(&help);

  // Add the help command to the shell
  HelpCommand helpCommand(helpCommands);
  shell.commands.push_back(&helpCommand);

  // Start of the program
  shell.run();
  return 0;
}