#include <iostream>
#include <vector>
#include <ios>       // streamsize
#include <iomanip>   // setprecision
#include <algorithm> // sort

struct Student_info
{
  std::string name;
  double midterm_grade;
  double final_exam_grade;
  std::vector<double> homework_grades;
};

// intentionally using std::vector<> instead of std::vector<>&
// so that the sorting doesn't affect the user of this function
double median(std::vector<double> homework_grades)
{
  std::vector<double>::size_type vector_size = homework_grades.size();
  if (vector_size == 0)
  {
    throw std::domain_error("cannot compute median of an empty vector");
  }

  std::sort(homework_grades.begin(), homework_grades.end());

  std::vector<double>::size_type mid = vector_size / 2;
  if (homework_grades.size() % 2 == 0)
  {
    return (homework_grades[mid] + homework_grades[mid - 1]) / 2;
  }
  return homework_grades[mid];
}

// calculation is given by school policies. Homework grade should be the middle grade instead of e.g. an average
double grade(const Student_info &student)
{
  return 0.2 * student.midterm_grade + 0.4 * student.final_exam_grade + 0.4 * median(student.homework_grades);
}

std::istream &read(std::istream &in, Student_info &student)
{
  if (!in)
  {
    throw std::domain_error("Invalid input stream");
  }

  student.homework_grades.clear();

  std::cout << "Enter homework homework_grades for this student: ";
  double current_homework_grade;
  while (std::cin >> current_homework_grade)
  {
    student.homework_grades.push_back(current_homework_grade);
  }

  // clear input stream bit flags (failure, eos, ...)
  in.clear();

  return in;
}

int main()
{

  Student_info student;
  std::cout << "\tGRADING 2.0\n";
  std::cout << "Enter student name: ";
  std::cin >> student.name;

  std::cout << "Enter midterm grade: ";
  std::cin >> student.midterm_grade;

  double final_exam_grade = 0;
  std::cout << "Enter final exam grade: ";
  std::cin >> student.final_exam_grade;

  read(std::cin, student);

  std::cout << "\n"
            << std::string('=', 15) << '\n';

  std::streamsize precision = std::cout.precision();
  std::cout << "Grading student " << student.name << '\n';
  try
  {
    std::cout << "Final grade is " << std::setprecision(3) << grade(student) << std::setprecision(precision) << std::endl;
  }
  // we don't have to but can catch errors with variables, e.g.
  // catch (const std::domain_error &err)
  catch (std::domain_error)
  {
    std::cerr << "Error: Student " << student.name << " has no homework grades" << std::endl;
    return 1;
  }

  return 0;
}