#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main()
{
  // vectors grow in size as needed
  std::vector<int> favorite_numbers;
  std::cout << "Enter your favorite numbers: ";

  int number;
  // while we are able to read a number
  while (std::cin >> number)
  {
    favorite_numbers.push_back(number);
  }

  // rename vector size type to a more compact naming
  typedef std::vector<int>::size_type vector_size;
  vector_size favorite_numbers_count = favorite_numbers.size();

  if (favorite_numbers_count == 0)
  {
    // interesting way to avoid outputing on the same line
    std::cout << std::endl
              << "Error: You must enter at least 1 number" << std::endl;
    return 1;
  }

  std::cout << "You've provided " << favorite_numbers_count << " numbers!" << std::endl;
  // interestingly enough we need to say where from and
  // where to we want to sort the vector.
  sort(favorite_numbers.begin(), favorite_numbers.end());
  std::cout << "Your numbers in sorted order: ";

  double average = 0;
  for (int i = 0; i < favorite_numbers_count; i++)
  {
    average += favorite_numbers[i];
    std::cout << favorite_numbers.at(i); // equivalent to: favorite_numbers[i]
    if (i < favorite_numbers_count - 1)
    {
      std::cout << ", ";
      average /= favorite_numbers_count;
    }
  }
  std::cout << std::endl;

  std::streamsize original_precision = std::cout.precision();
  std::cout << "Average of your numbers is: "
            // double precision to 3 places, see documentation for details
            << std::setprecision(5)
            << average
            << std::setprecision(original_precision) << std::endl;

  return 0;
}
