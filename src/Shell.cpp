#include <iostream>
#include "Shell.h"

Shell::Shell()
{
  std::cout << "Shell started!" << std::endl;
}

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
  std::cout << "Unknown command: " << command << std::endl;
}