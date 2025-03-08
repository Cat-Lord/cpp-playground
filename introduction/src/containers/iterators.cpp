#include <iostream>
#include <vector>

int main()
{

  std::cout << "We'll quickly look at iterators of containers in general.\n";
  std::vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};

  // a normal mutable iterator
  for (auto it = nums.begin(); it != nums.end(); it++)
  {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  // a read-only iterator, meaning we cannot alter the items
  for (auto it = nums.cbegin(); it != nums.cend(); it++)
  {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  // a reversed iterator, useful when traversing from the end. Output will be "9 8 7 ..."
  for (auto it = nums.rbegin(); it != nums.rend(); it++)
  {
    std::cout << *it << ' ';
  }
  std::cout << '\n';

  std::cout << "We can utilize iterators to initialize new containers like this: std::vector<int> nums_copy(nums.begin(), nums_end_iter)\n";
  std::vector<int>::iterator nums_end_iter = nums.begin();
  std::advance(nums_end_iter, 4);
  std::vector<int> nums_copy(nums.begin(), nums_end_iter);
  std::cout << "Copied vector now has items: ";
  for (const auto &item : nums_copy)
  {
    std::cout << item << ' ';
  }
  std::cout << '\n';

  std::cout << "When we change the containers, usually the iterators get invalidate. This is the case in e.g. item removal in vectors.\n";
  std::vector<int>::const_iterator iter = nums.cbegin();
  nums.push_back(10);
  nums.push_back(11);
  nums.push_back(12);
  std::vector<int>::const_iterator new_iter = nums.cbegin();
  if (&iter != &new_iter)
  {
    std::cout << "Previous iterator is now invalid, because it differs from the current one:\n";
    std::cout << "\tOld iterator: " << &iter << '\n';
    std::cout << "\tNew iterator: " << &new_iter << '\n';
  }

  return 0;
}