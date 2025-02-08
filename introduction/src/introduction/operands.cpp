#include <iostream>

// Cats are love
/**
 * A main function must return a value, otherwise we'll get an error.
 * */
int main()
{
  // left-associative, meaning this...
  std::cout << "Cats are love!" << std::endl;
  // is equal to
  (std::cout << "Cats are love!") << std::endl;

  // operand "<<" takes the most left values available, as seen above
  // and then returns the left side. Here we can see it in action;
  std::ostream &output = std::cout << "Meow Meow";
  std::cout << &output << std::endl;
  // Note: the output from the line above is not perfect and contains some additional characters

  return 0;
}