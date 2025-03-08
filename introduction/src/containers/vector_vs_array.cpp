#include <iostream>
#include <random>
#include <array>
#include <vector>

std::random_device rd;                       // Seed generator
std::mt19937 gen(rd());                      // Mersenne Twister engine
std::uniform_int_distribution<> dis(1, 100); // Range [1, 100]

// Define the range for the random numbers
int random_int()
{
  int random_number = dis(gen);
  std::cout << "...generated " << random_number << '\n';
  return random_number;
}

void print_vector(std::vector<int> &vector)
{
  std::cout << "Printing vector with addresses (" << vector.size() << " number of items):\n";

  for (const int &item : vector)
  {
    std::cout << "\t[" << &item << "] " << item << '\n';
  }
  std::cout << '\n';
}

int main()
{

  std::cout << "In this example we'll look at differences between vectors and arrays\n";
  std::cout << "Arrays have to have a predefined length - they are not resizable (at least not for free)";
  std::array<int, 10> int_arr;

  // iterating through array is safe this way, because the memory is contiguous
  for (int i = 0; i < int_arr.size(); i++)
  {
    std::cout << int_arr[i] << ' ';
  }
  std::cout << '\n';

  std::cout << "Now using vectors let's create a vector with only 5 items (for now)\n";
  std::vector<int> int_vec(5);
  std::cout << "Now we'll insert 5 items\n";
  int *first_item_address = &int_vec[0];
  int_vec[0] = random_int();
  int_vec[1] = random_int();
  int_vec[2] = random_int();
  int_vec[3] = random_int();
  int_vec[4] = random_int();
  print_vector(int_vec);
  std::cout << "Look carefully at the addresses above. Let's now add a new element.\n";
  int_vec.push_back(random_int());
  print_vector(int_vec);
  std::cout << "Look, all the addresses have changed! This is because the vector CAN accept new items, but it needs to find a new place in memory to put them\n";
  std::cout << "Let's see if adding another item changes the addresses again.";
  int_vec.push_back(random_int());
  print_vector(int_vec);
  int_vec.push_back(random_int());
  print_vector(int_vec);
  int_vec.push_back(random_int());
  print_vector(int_vec);
  int_vec.push_back(random_int());
  print_vector(int_vec);
  std::cout << "We can see that the behaviour seems random, but this is because when the vector finds a new location, it allocates more place than just one.\n";
  std::cout << "This is because it expects you to add a couple of items, not just one. If we exceed the size again, vector is moved and addresses also change.\n";
  std::cout << '\n';
  std::cout << "Because of this it's dangerous to store pointers to vector elements. We've stored the first element before calling all the push_back() operations and look...\n";
  std::cout << "\t" << first_item_address << " <- See? Is it equal to the first element's address in the last output above? Scary!\n";
  std::cout << '\n';

  std::cout << "Because of this reason we have a couple of options on how to iterate through the vector.\n";

  // get every element using iterators
  std::vector<int>::const_iterator iter = int_vec.cbegin();
  std::vector<int>::const_iterator iter_end = int_vec.cbegin();
  for (; iter < iter_end; iter++)
  {
    std::cout << *iter << ' ';
  }
  std::cout << '\n';

  std::cout << '\n';
  std::cout << "...but there is even an easier approach: ranged for-loop\n";
  for (const int &item : int_vec)
  {
    std::cout << "\t[" << &item << "] " << item << '\n';
  }
  std::cout << '\n';

  std::cout << "Quick, safe, elegant!\n";
  std::cout << "Last thing we'll discuss is delete operation. Whilst in array a deletion is not really possible (";
  std::cout << "because the space for items is already allocated), in vectors we can remove items. This is, ";
  std::cout << "arguably, so inefficient for larger amount of items, that it's best to avoid it completely.";
  std::cout << "Let's try deleting some elements and look at addresses again.";
  std::cout << "This is the array again before deletion:\n";
  print_vector(int_vec);

  std::vector<int>::const_iterator int_vec_iter = int_vec.cbegin();
  std::advance(int_vec_iter, 2);
  int_vec.erase(int_vec_iter);
  print_vector(int_vec);
  std::cout << "Carefully observing the output, we notice that all the items shifted their address based on the location of the deleted element.";
  std::cout << "This is highly inefficient, because the contents need to be copied. A more efficient solution might be to use (linked) lists.";
  std::cout << "We have to consider the use case, because lists don't have a quick random access but have fast deletion.";

  std::cout << std::endl;

  return 0;
}