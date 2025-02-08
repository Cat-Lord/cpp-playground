
#include <iostream>

int main()
{
  std::string name = "My Name is a name";
  std::string::size_type size = name.size();
  std::cout << "Size of string '" << name << "' is " << size << std::endl;

  return 0;
}
