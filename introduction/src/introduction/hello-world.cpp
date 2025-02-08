// includes may appear only by themselves, with a comment exception
#include <iostream>

// Cats are love
/**
 * A main function must return a value, otherwise we'll get an error.
 * */
int main()
{
  int num = 1;
  std::cout << "Cats are love!" << std::endl;
  std::cout << num;
  std::cout << "!";
  std::cout << std::endl;

  // String literals may not stretch over lines. Code below
  // would throw an error.
  // std::cout << "Cats
  // are
  // love!" << std::endl;

  // the return below is optional in main, but highly recommended
  return 0;
}