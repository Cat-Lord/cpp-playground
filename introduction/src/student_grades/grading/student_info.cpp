#include "student_info.hpp"

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
