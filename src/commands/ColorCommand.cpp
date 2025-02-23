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

    for (int i = 0; i < hue::NAMES.size(); i++)
    {
      if (args.front() == hue::NAMES.at(i))
      {
        std::string color = hue::NAMES.at(i);
        hue::set_text(color);
        return;
      }
    }
    std::cout << "Unknown color" << std::endl;
  }
};