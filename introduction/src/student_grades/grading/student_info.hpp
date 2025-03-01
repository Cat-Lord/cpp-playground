#ifndef __STUDENT_INFO_HPP_
#define __STUDENT_INFO_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "median.hpp"

struct Student_info
{
  std::string name;
  double midterm_grade;
  double final_exam_grade;
  std::vector<double> homework_grades;
};

std::istream &read(std::istream &in, Student_info &student);
double grade(const Student_info &student);

#endif