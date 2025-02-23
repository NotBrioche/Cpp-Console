#include <iostream>

#include "Command.h"
#include "Shell.h"

class HistoryCommand : public Command
{
public:
  HistoryCommand(Shell *shell)
  {
    this->name = "history";
    this->description = "display the last 15 commands done";
    this->syntax = "history";
    this->shell = shell;
  };

  Shell *shell;

  void execute(std::list<std::string> &args) override
  {
    if (shell->history.size() < 1)
        std::cout << "You havn't sent any commands" << std::endl;

    for (auto const &i : shell->history)
    {
      std::cout << i << std::endl;
    }
  }
};