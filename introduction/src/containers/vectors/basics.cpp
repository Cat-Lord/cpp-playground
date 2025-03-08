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
    }
    else
    {
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

  std::cout << "If we have two vectors that we want to concatenate, we can do it simply by inserting into vector based on iterators\n";
  // copy the favorite numbers
  std::vector<int> base_numbers = favorite_numbers;
  std::vector<int> additional_numbers{99, 100, 101, 102, 103};

  // inserting into base vector using iterators from appended vector
  base_numbers.insert(base_numbers.end(), additional_numbers.begin(), additional_numbers.end());
  std::cout << "BASE NUMBERS (with new appended numbers)\n";
  for (const int &item : base_numbers)
  {
    std::cout << "\t" << item << '\n';
  }
  std::cout << '\n'
            << std::endl;

  std::cout << "We can RESERVE memory in advance, when we know how many items to expect.\n";
  std::cout << "The number of items a vector can hold before re-allocating is determined by the vector::capacity member.\n";
  std::vector<double> nums;
  std::cout << "\tInitial capacity: " << nums.capacity() << '\n';
  nums.reserve(10);
  std::cout << "\tCapacity after vector::reserve(10): " << nums.capacity() << '\n';
  std::cout << "Having a vector for floating-point numbers we can look at how many elements it has based on its size(): " << nums.size() << '\n';
  std::cout << "Inserting new items we will take a look at the memory changes, let's see...\n";
  auto begin = nums.data();
  std::cout << "\tVector address before insertion: " << begin << '\n';
  nums.push_back(1.0);
  nums.push_back(2.0);
  nums.push_back(3.0);
  nums.push_back(4.0);
  nums.push_back(5.0);
  nums.push_back(6.0);
  nums.push_back(7.0);
  nums.push_back(8.0);
  nums.push_back(9.0);
  auto end = nums.data();
  std::cout << "\tVector address after 9 insertions: " << end << '\n';

  std::cout << "If we wanted to have more control over the vector size, we could use vector::resize.\n";
  nums.resize(20);
  std::cout << "Size and capacity after resize(20): size " << nums.size() << " and capacity " << nums.capacity() << ".\n";
  std::cout << "The only thing to be careful about is that if we downsize, overflown elements will be lost.";
  return 0;
}
