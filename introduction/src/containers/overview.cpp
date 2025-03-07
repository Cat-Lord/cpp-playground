#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <unordered_set>
#include <list>
#include <map>

struct Student
{
  std::string first_name;
  double final_grade;
};

void showcase_maps()
{
  std::map<std::string, Student> student_map;

  student_map.insert({"Mark", {"Mark", 1.8}});
  student_map.insert({"Oddy", {"Oddy", 2.3}});
  student_map.insert({"Peter", {"Peter", 1.9}});

  // the way we fetch map elements is quite fast (performance-wise)
  Student mark = student_map.at("Mark");
  // When querying elements we can check if there is at least 1 item available for a key
  std::cout << "Number of items for key 'Mark': " << student_map.count("Mark") << '\n';
  std::cout << "Number of items for key 'random': " << student_map.count("random") << std::endl;
}

void showcase_ordered_sets()
{
  // custom way to compare two students
  auto comparator = [](Student a, Student b)
  { return a.first_name < b.first_name; };
  // a little bit of magic to overwrite the default comparator
  std::set<Student, decltype(comparator)> students(comparator);

  students.insert({"Mark", 1.5});
  students.insert({"Andrea", 2.5});
  students.insert({"Xenia", 1.1});
  students.insert({"Norbert", 3.2});

  std::cout << "STUDENTS SET: \n";
  for (const Student &student : students)
  {
    std::cout << "\t" << student.first_name << ": " << student.final_grade << '\n';
  }
}

void empty_line()
{
  std::cout << std::endl;
}

int main()
{

  std::cout << "Containers store multiples of the same data" << '\n';

  //
  // ARRAY
  //
  std::cout << "The simplest of all is the array" << '\n';

  int arr[10];                    // statically allocated with rubbish in each element
  int *dynamic_arr = new int[10]; // dynamically allocated & needs to be freed when not needed anymore
  free(dynamic_arr);

  std::cout << "Accessing elements is simple and could also be dangerous" << '\n';
  std::cout << "Element on the 6th position in the array: " << arr[5] << '\n';
  // accessing elements outside of the array doesn't throw error, but rather an unexpected value
  std::cout << "Element on the 26th position in the array" << arr[26] << std::endl;
  empty_line();

  std::cout << "It's also cumbersome to remember and always propagate the array length everywhere." << '\n'
            << "Therefore we'll use an extension of the array: vectors" << '\n';
  // iterating through them is susceptible to human errors
  for (int i = 0; i < 10; i++)
  {
    std::cout << arr[i] << " ";
  }
  std::cout << '\n';
  empty_line();

  //
  // VECTOR
  //
  std::vector<int> int_v;
  std::cout << "Vectors are arrays on steroids - they grow as needed, albeit they need to be copied to another memory location when the free memory space is not sufficient to hold any more items in the vector" << '\n';
  std::cout << "They still act as arrays but with advantages" << '\n';
  empty_line();

  std::cout << "\t- no need to define the size up-front\n";
  int_v.push_back(15);
  int_v.push_back(8);
  int_v.push_back(10);
  int_v.push_back(4);

  std::cout << "\t- can get size simply by calling the vector.size() function, e.g." << int_v.size() << '\n';
  std::cout << "\t- iterating through a vector is improved with iterators\n";
  // vector indices iterator
  for (std::vector<int>::iterator vec_iter = int_v.begin(); vec_iter < int_v.end(); vec_iter++)
  {
    std::cout << *vec_iter << ' ';
  }
  std::cout << '\n';
  empty_line();

  // the most ideal form is using iterators getting the items directly
  for (int &item : int_v)
  {
    std::cout << item << ' ';
  }
  std::cout << '\n';
  empty_line();

  //
  // DEQUE
  //
  std::deque<int> int_deq;
  std::cout << "Another similar data container is deque. It allows fast insertion and deletion both from the back and the front";
  int_deq.push_front(9);
  int_deq.push_front(8);
  int_deq.push_front(7);

  int_deq.push_back(1);
  int_deq.push_back(2);
  int_deq.push_back(3);

  // kinda clumsily: we have to fetch the element before removing it from the deque
  int last_item = int_deq.back();
  std::cout << "Last element is: " << last_item << " and number of items is " << int_deq.size() << std::endl;
  int_deq.pop_back();
  std::cout << "After removal and number of items is " << int_deq.size() << std::endl;
  empty_line();

  //
  // SET (ordered, unordered)
  //
  std::set<int> int_set;
  int_set.insert(1);
  int_set.insert(7);
  int_set.insert(4);
  int_set.insert(4);
  // notice that 4 appears only once in the set - all items are unique
  // notice that item needs to be const int&, not only int&
  //    - the reason is that set is a read-only data structure and we're not able to
  //      change the date, hence the "const"
  for (const int &item : int_set)
  {
    std::cout << item << ' ';
  }
  std::cout << '\n';
  empty_line();

  // by default the set is an ordered set - based on a comparator it sorts it's values
  // on each insertion
  showcase_ordered_sets();
  empty_line();

  std::cout << "Lists are really similar to arrays with the huge difference that they are not sequential: we cannot simply get n-th element in an almost-constant time, because we have to iterate over list items N times in order to get there. This is because the addresses are not sequential in memory" << std::endl;
  std::list<std::string> string_list;
  string_list.push_back("abcd");
  string_list.push_back("xyz");
  string_list.push_back("mnop");
  // a clumsy way of getting the third item
  std::list<std::string>::const_iterator string_list_iterator = string_list.cbegin();
  std::advance(string_list_iterator, 2);
  std::cout << "Third list item: " << *string_list_iterator << std::endl;
  empty_line();

  // unordered sets come as easy as they sound
  std::unordered_set<std::string> unordered_set;
  unordered_set.insert("Kefir");
  unordered_set.insert("Elis");
  unordered_set.insert("Berry");
  unordered_set.insert("Eddie");
  std::cout << "Showing unordered set items: \n";
  for (const std::string &item : unordered_set)
  {
    std::cout << item << ' ';
  }
  std::cout << '\n';
  empty_line();

  showcase_maps();

  return 0;
}