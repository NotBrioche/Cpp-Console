#include <iostream>
#include <sstream>
#include <algorithm>
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
  std::list<std::string> parts = getParts(command);
  for (auto const &i : commands)
  {
    if (parts.front() == i->getName())
    {
      parts.pop_front();
      i->execute(parts);
      return;
    }
  }

  std::cout << "Unknown command: " << parts.front() << std::endl;
}

std::list<std::string> Shell::getParts(const std::string &command)
{
  std::stringstream s(command);

  std::string part;

  std::list<std::string> args;

  bool quoted = false;
  std::string quotedString;

  while (s >> part)
  {
    if (part.find("\"") != std::string::npos)
    {
      if (quoted)
      {
        quotedString += part;
        std::replace(quotedString.begin(), quotedString.end(), '\"', '\0');
        args.push_back(quotedString);
        quotedString = "";
        continue;
      }

      quoted = !quoted;
    }

    if (!quoted)
      args.push_back(part);
    else
      quotedString += part.append(" ");
  }

  return args;
}

void Shell::saveCommand(std::string command)
{
  history.push_back(command);
  if (history.size() > 15)
    history.pop_front();
}