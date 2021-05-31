// source file for Student_info-related functions
#include "Student_info_v2.h"

#include <stdexcept>
#include <string>

#include "grade_v2.h"

using std::domain_error;
using std::istream;
using std::string;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
  return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
  // read and store the student's name and midterm and final exam grades
  double midterm, final;
  vector<double> homework;
  is >> s.name >> midterm >> final;

  read_hw(is, homework);

  try {
    s.finalGrade = grade(midterm, final, homework);
  } catch (domain_error e) {
    s.finalGrade = -1;
  }

  return is;
}

istream& read_hw(istream& in, vector<double>& hw) {
  if (in) {
    // get rid of previous contents
    hw.clear();

    // read homework grades
    double x;
    while (in >> x) hw.push_back(x);

    in.clear();
  }
  return in;
}
