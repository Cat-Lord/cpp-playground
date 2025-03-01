#include <iostream>
#include <vector>
#include <ios>       // streamsize
#include <iomanip>   // setprecision
#include <algorithm> // sort

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
double grade(double midterm, double final, std::vector<double> homework_grades)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * median(homework_grades);
}

int main()
{

  std::string name;
  std::cout << "\tGRADING 1.0\n";
  std::cout << "Enter student name: ";
  std::cin >> name;

  double midterm_grade = 0;
  std::cout << "Enter midterm grade: ";
  std::cin >> midterm_grade;

  double final_exam_grade = 0;
  std::cout << "Enter final exam grade: ";
  std::cin >> final_exam_grade;

  std::vector<double> homework_grades;
  double current_grade;
  std::cout << "Enter homework homework_grades for this student: ";
  while (std::cin >> current_grade)
  {
    homework_grades.push_back(current_grade);
  }

  // this is also one possible typedef use case
  typedef std::vector<double>::size_type vector_size_type;
  vector_size_type homework_grades_count = homework_grades.size();
  if (homework_grades_count == 0)
  {
    std::cerr << "No homework homework_grades entered. Make sure to enter homework homework_grades to calculate the final grade" << std::endl;
    return 1;
  }

  std::cout << "\n"
            << std::string('=', 15) << '\n';

  std::streamsize precision = std::cout.precision();
  std::cout << "Grading student " << name << '\n';
  std::cout << "Final grade is " << std::setprecision(3) << grade(midterm_grade, final_exam_grade, homework_grades) << std::setprecision(precision) << std::endl;
  return 0;
}