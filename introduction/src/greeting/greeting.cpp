#include <iostream>
#include <string>

// using initialization functions
std::string create_efficient_greeting(std::string name)
{
  const std::string greeting = "* Hello " + name + "! *";
  // creates a string with greeting.length() length and fills it with the '*' character
  // similar construct exists for other types, e.g. vectors
  // It's called a `fill constructor`
  const std::string horizontal_frame(greeting.length(), '*');
  // just another way of creating strings with the 'string' function
  std::string vertical_frame = std::string(greeting.length() - 2, ' ');
  vertical_frame = "*" + vertical_frame + "*";
  return horizontal_frame + "\n" + vertical_frame + "\n" + greeting + "\n" + vertical_frame + "\n" + horizontal_frame;
}

// Simple approach
std::string create_greeting(std::string name)
{
  // we are able to make variables constant using "const"
  const std::string greeting = "* Hello " + name + "! *";
  std::string frame_horizontal_line;
  for (char i = 0; i < greeting.length(); i++)
  {
    frame_horizontal_line += "*";
  }

  std::string frame_vertical_line = "*";
  for (char i = 0; i < greeting.length() - 2; i++)
  {
    frame_vertical_line += " ";
  }
  frame_vertical_line += "*";

  return frame_horizontal_line + "\n" + frame_vertical_line + "\n" + greeting + "\n" + frame_vertical_line + "\n" + frame_horizontal_line + "\n ";
}

int main()
{

  std::string name;
  std::cout << "Introduce yourself: ";
  std::cin >> name;

  std::cout << create_efficient_greeting(name) << std::endl;
  return 0;
}