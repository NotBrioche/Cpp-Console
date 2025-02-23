#include <iostream>

#include "Command.h"
#include "color.hpp"

class ColorCommand : public Command
{
public:
  ColorCommand()
  {
    this->name = "color";
    this->description = "change the color of the console";
    this->syntax = "color [color]";
  };

  void execute(std::list<std::string> &args) override
  {
    if (checkArguments(args, 1, "Please enter a color"))
      return;

    if (hue::CODES.find(args.front()) != hue::CODES.end())
    {
      hue::set_text(args.front());
      return;
    }

    std::cout << "Unknown color" << std::endl;
  }
};