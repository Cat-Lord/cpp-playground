#include <iostream>
#include <string>

int main()
{
  std::string name;

  std::cout << "Your favourite cat: ";
  std::cin >> name; // this automatically flushes the buffer. Although it sounds kinda bad to rely on it./
  std::cout << std::endl;

  // 2 ways of writing this
  // first: concatenate with +
  std::cout << "Fabulous, we also love " + name << std::endl;
  // second: concatenate output streams
  std::cout << "Also, " << name << " is an awesome name" << std::endl;
  return 0;
}