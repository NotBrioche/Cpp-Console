#include "Shell.h"

// Include commands
#include "ClearCommand.cpp"
#include "EchoCommand.cpp"
#include "HelpCommand.cpp"
#include "ColorCommand.cpp"

int main()
{

  ClearCommand clearCommand;
  EchoCommand echoCommand;
  ColorCommand colorCommand;

  Shell shell;

  // Add commands to the shell
  shell.commands.push_back(&clearCommand);
  shell.commands.push_back(&echoCommand);
  shell.commands.push_back(&colorCommand);

  // Prepare hard coded commands for the help command
  std::list<Command *> helpCommands = shell.commands;
  Command exit("exit", "exits the shell", "exit");
  Command help("help", "display the list of commands", "help");
  Command history("history", "display the last 15 commands sent", "history");
  helpCommands.push_back(&exit);
  helpCommands.push_back(&help);
  helpCommands.push_back(&history);

  // Add the help command to the shell
  HelpCommand helpCommand(helpCommands);
  shell.commands.push_back(&helpCommand);

  // Start of the program
  shell.run();
  return 0;
}