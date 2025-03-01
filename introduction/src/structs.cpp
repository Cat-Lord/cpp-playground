#include <iostream>
#include <vector>
#include <algorithm>

struct Student
{
  double averageGrade;
  std::string name;
};

// custom comparator for the sort function
bool compare_students(Student &first, Student &second)
{
  return first.averageGrade < second.averageGrade;
}

int main()
{
  // vector of size 3
  std::vector<Student> students(3);

  students[0] = {0.5, "Meow"};
  students[1] = {0.2, "Woof"};
  students[2] = {0.7, "Blop"};

  std::cout << "Students before sorting:\n";
  for (const Student &student : students)
  {
    std::cout << "\t" << student.name << ": " << student.averageGrade << "\n";
  }
  std::cout << std::endl;

  sort(students.begin(), students.end(), compare_students);

  std::cout << "Students after sorting:\n";
  for (const Student &student : students)
  {
    std::cout << "\t" << student.name << ": " << student.averageGrade << "\n";
  }
  std::cout << std::endl;

  return 0;
}