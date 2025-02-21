#include <iostream>

using std::cout;
using std::endl;

int SPACING = 3;

std::string create_vertical_spacing_lines(std::string vertical_line)
{
  std::string output = "";
  for (int i = 0; i < SPACING; i++)
  {
    output += vertical_line;
    if (i < SPACING - 1)
    {
      output += "\n";
    }
  }
  return output;
}

std::string create_frame_greeting(std::string name)
{
  std::string greeting = "";
  std::string horizontal_line(name.length() + SPACING * 2 + 2, '*');
  std::string vertical_line(name.length() + SPACING * 2, ' ');
  vertical_line = '*' + vertical_line + '*';
  std::string vertical_space_lines = create_vertical_spacing_lines(vertical_line);
  std::string empty_space(SPACING, ' '); // space within line, e.g. "*   <space>    *"

  greeting += horizontal_line + "\n";
  greeting += vertical_space_lines + "\n";
  greeting += "*" + empty_space + name + empty_space + "*" + "\n";
  greeting += vertical_space_lines + "\n";
  greeting += horizontal_line + "\n";

  return greeting;
}

int main()
{

  while (true)
  {
    std::string name;
    cout << "Enter your name: ";
    std::cin >> name;

    cout << create_frame_greeting(name) << endl;
    cout << "\n\n\n\n"
         << endl;
  }
  return 0;
}