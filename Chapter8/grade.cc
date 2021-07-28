#include "grade.h"

#include <stdexcept>
#include <vector>
#include <algorithm>

#include "Student_info.h"
#include "median.h"

using std::domain_error;
using std::vector;

double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
  if (hw.size() == 0) throw domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade_iter(double midterm, double final, vector<double>& hw) {
  if (hw.size() == 0) throw domain_error("student has done no homework");
  std::sort(hw.begin(), hw.end());
  return grade(midterm, final, median_iter(hw.begin(), hw.end()));
}

double grade(const Student_info& s) {
  return grade(s.midterm, s.final, s.homework);
}

double grade_iter(Student_info& s) {
  return grade_iter(s.midterm, s.final, s.homework);
}
