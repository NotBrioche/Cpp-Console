#include <iostream>
#include <sstream>
#include "Shell.h"

void Shell::run()
{
  std::string command;
  while (true)
  {
    std::cout << "> ";
    std::getline(std::cin, command);

    if (command.size() < 1)
      continue;

    if (command == "exit")
      break;

    executeCommand(command);
    saveCommand(command);
  }
}

void Shell::executeCommand(const std::string &command)
{
  for (auto const &i : commands)
  {
    std::list<std::string> parts = getParts(command);

    if (parts.front() == i->getName())
    {
      parts.pop_front();
      i->execute(parts);
      return;
    }
  }

  std::cout << "Unknown command: " << command << std::endl;
}

std::list<std::string> Shell::getParts(const std::string &command)
{
  std::stringstream s(command);

  std::string part;

  std::list<std::string> args;

  while (s >> part)
  {
    args.push_back(part);
  }

  return args;
}

void Shell::saveCommand(std::string command)
{
  history.push_back(command);
  if (history.size() > 15)
    history.pop_front();
}