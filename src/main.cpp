#include "Shell.h"

// Include commands
#include "ClearCommand.cpp"
#include "EchoCommand.cpp"
#include "HelpCommand.cpp"
#include "ColorCommand.cpp"
#include "SaveCommand.cpp"
#include "HistoryCommand.cpp"

int main()
{

  Shell shell;

  ClearCommand clearCommand;
  EchoCommand echoCommand;
  ColorCommand colorCommand;
  SaveCommand saveCommand(&shell);
  HistoryCommand historyCommand(&shell);

  // Add commands to the shell
  shell.commands.push_back(&clearCommand);
  shell.commands.push_back(&echoCommand);
  shell.commands.push_back(&colorCommand);
  shell.commands.push_back(&saveCommand);
  shell.commands.push_back(&historyCommand);

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