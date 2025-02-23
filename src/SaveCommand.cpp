#include "Command.h"
#include "Shell.h"

class SaveCommand : public Command
{
public:
  SaveCommand(Shell *shell)
  {
    this->name = "save";
    this->description = "save the history of commands in a file";
    this->syntax = "save [file]";
    this->shell = shell;
  };

  Shell *shell;

  void execute(std::list<std::string> &args) override
  {
    std::string fileString;
    for (auto const &i : shell->history)
    {
      fileString.append(i + '\t');
    }

    std::string commandString = "echo " + fileString + " > " + args.front();
    system(commandString.c_str());
  }
};