#include <iostream>
#include <random>
#include <chrono>
#include <list>

std::random_device rd;                       // Seed generator
std::mt19937 gen(rd());                      // Mersenne Twister engine
std::uniform_int_distribution<> dis(1, 100); // Range [1, 100]

struct Cat
{
  std::string name;
  int cuteness;
};

// Define the range for the random numbers
int random_int()
{
  int random_number = dis(gen);
  return random_number;
}

int main()
{

  std::cout << "This example will test the efficiency of insert operations on a list. We'll create rather large list with many items.\n";
  std::list<Cat> cat_list;
  for (int i = 0; i < 1'000'000; i++)
  {
    cat_list.push_back({"Cat " + std::to_string(i), random_int()});
  }
  std::cout << "Initial insertion complete, the size is " << cat_list.size() << " elements.\n";

  std::cout << "Now let's push_back a new item and see how much time it takes.\n";

  // traditional push_back
  auto start_time = std::chrono::high_resolution_clock::now();
  cat_list.push_back({"New cat", 69});
  auto end_time = std::chrono::high_resolution_clock::now();
  auto duration = end_time - start_time;
  std::cout << "Traditional push back took " << duration.count() << " ms.\n";

  // list::end + list::insert
  start_time = std::chrono::high_resolution_clock::now();
  cat_list.insert(cat_list.end(), {"New cat", 69});
  end_time = std::chrono::high_resolution_clock::now();
  duration = end_time - start_time;
  std::cout << "Using 'list::end' with 'list::insert' took " << duration.count() << " ms.\n";

  // list::push_front
  start_time = std::chrono::high_resolution_clock::now();
  cat_list.push_front({"New cat", 69});
  end_time = std::chrono::high_resolution_clock::now();
  duration = end_time - start_time;
  std::cout << "Using 'list::push_front' took " << duration.count() << " ms.\n";
  return 0;
}