#include <iostream>
#include "student_info.hpp"
#include <ios>     // streamsize
#include <iomanip> // setprecision

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