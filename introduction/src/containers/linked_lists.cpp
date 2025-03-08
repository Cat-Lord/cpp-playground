#include <iostream>
#include <random>
#include <list>

std::random_device rd;                       // Seed generator
std::mt19937 gen(rd());                      // Mersenne Twister engine
std::uniform_int_distribution<> dis(1, 100); // Range [1, 100]
int max_number = 0;

struct Cat
{
  std::string name;
  int cuteness;
};

// Define the range for the random numbers
int random_int()
{
  int random_number = dis(gen);
  if (random_number > max_number)
  {
    max_number = random_number;
  }

  std::cout << "...generated " << random_number << '\n';
  return random_number;
}

void print_list(std::list<Cat> &list)
{
  std::cout << "Printing vector with addresses (" << list.size() << " number of items):\n";

  for (const Cat &item : list)
  {
    std::cout << "\t[" << &item << "] " << item.cuteness << ": " << item.name << '\n';
  }
  std::cout << '\n';
}

int main()
{

  std::cout << "Here we'll take a look at lists and deletion of its items.\n";
  std::list<Cat> cat_list;
  cat_list.push_back({"Felicita", random_int()});
  cat_list.push_back({"Anita", random_int()});
  cat_list.push_back({"Elis", random_int()});
  cat_list.push_back({"Kocicanda", random_int()});
  cat_list.push_back({"Snowie", random_int()});

  std::cout << "Now that we have the items in the list, let's try and iterate over that list and remove every item thats more than 10.\n";

  print_list(cat_list);

  std::cout << "One way to delete an item while iterating over it is to receive an updated iterator when we call 'erase'\n";
  std::list<Cat>::iterator list_iter = cat_list.begin();
  for (; list_iter != cat_list.end();)
  {
    if (list_iter->name == "Kocicanda")
    {
      std::cout << "...erasing cat " << list_iter->name << '\n';
      // receive an updated iterator
      list_iter = cat_list.erase(list_iter);
    }
    else
    {
      list_iter++;
    }
  }

  std::cout << "Another way might be to use a helper array to denote every address that needs deleting\n";
  std::list<std::list<Cat>::const_iterator> to_remove;
  for (auto iter = cat_list.cbegin(); iter != cat_list.cend(); iter++)
  {
    if (iter->cuteness > 10)
    {
      std::cout << "\t...Marking for removal [" << &iter << "] " << iter->name << "\n";
      to_remove.push_back(iter);
    }
  }
  std::cout << '\n';

  std::cout << "We now have " << to_remove.size() << " items to remove\n";
  for (const auto to_remove_iter : to_remove)
  {
    std::cout << "...removing [" << &to_remove_iter << "] " << to_remove_iter->name << " (" << to_remove_iter->cuteness << ")\n";
    cat_list.erase(to_remove_iter);
  }

  return 0;
}