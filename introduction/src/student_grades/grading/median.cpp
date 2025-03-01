#include "median.hpp"

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