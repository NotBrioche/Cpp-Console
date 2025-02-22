#include <iostream>
#include "Shell.h"

void Shell::run()
{
  std::string command;
  while (true)
  {
    std::cout << "> ";
    std::getline(std::cin, command);

    if (command == "exit")
    {
      break;
    }

    executeCommand(command);
  }
}

void Shell::executeCommand(const std::string &command)
{
  for (auto const &i : commands)
  {
    if (command == i->getName())
    {
      i->execute();
      return;
    }
  }

  std::cout << "Unknown command: " << command << std::endl;
}