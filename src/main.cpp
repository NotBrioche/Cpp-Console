#include "Shell.h"
#include "Commands.h"

int main()
{

  Shell shell;

  std::list<Command*> commands = {
      new ClearCommand(),
      new EchoCommand(),
      new ColorCommand(),
      new SaveCommand(&shell),
      new HistoryCommand(&shell),
  };

  for (auto &cmd : commands) {
    shell.commands.push_back(cmd);
  }

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