// Section 6-2: Comparing grading schemes
// Pages: 111-116
//
// Uses various methods of calculating final grades.
//
// Must require all students to have the same number
// of grades as an input.

#include "analysis.h"

#include <algorithm>
#include <iostream>   // ostream, endl;
#include <numeric>    // numeric
#include <stdexcept>  // domain_error
#include <string>     // string
#include <vector>     // vector

#include "Student_info.h"  // Student_info
#include "grade.h"         // grade
#include "median.h"        // median

using std::endl;
using std::ostream;
using std::string;
using std::vector;

using std::accumulate;
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::transform;
using std::vector;

// Compute average of elements
// (S6.2.3/115)
double average(const vector<double>& v) {
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

// Compute the final grade using average of homework
// (S6.2.3/115)
double average_grade(const Student_info& s) {
  return grade(s.midterm, s.final, average(s.homework));
}

// Has the student done all the homework?
// (S6.2.1/110)
bool did_all_hw(const Student_info& s) {
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

// Auxiliary function to be parsed as argument to a function
// (S6.2.2/113)
double grade_aux(const Student_info& s) {
  try {
    return grade(s);
  } catch (domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist
double optimistic_median(const Student_info& s) {
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);
  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else
    return grade(s.midterm, s.final, median(nonzero));
}
