// Section 6-2: Comparing grading schemes
// Pages: 111-116
//
// Uses various methods of calculating final grades.
//
// Must require all students to have the same number
// of grades as an input.

#include <algorithm>  // transform
#include <algorithm>  // find
#include <algorithm>  // transform
#include <algorithm>  // remove_copy, back_inserter
#include <algorithm>  // transform
#include <iostream>   // cin, cout, endl
#include <iostream>   // ostream, endl;
#include <numeric>    // numeric
#include <stdexcept>  // domain_error
#include <string>     // string
#include <vector>     // vector

#include "Student_info.h"  // Student_info

using std::endl;
using std::ostream;
using std::string;
using std::vector;
#include "Student_info.h"  // Student_info
// #include "average.h"                     // average
// #include "average_analysis.h"            // average_analysis
// #include "average_grade.h"               // average_grade
// #include "did_all_hw.h"                  // did_all_hw
#include "grade.h"  // grade
// #include "grade_aux.h"                   // grade
#include "median.h"  // median
// #include "median_analysis.h"             // median_analysis
// #include "optimistic_median.h"           // optimistic_median
// #include "optimistic_median_analysis.h"  // optimistic_median_analysis
// #include "write_analysis.h"              // write_analysis

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

// Perform average analysis
// (S6.2.3/115)
double average_analysis(const vector<Student_info>& students) {
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades),
            average_grade);
  return median(grades);
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

// S6.2.2/112
double median_analysis(const vector<Student_info>& students) {
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
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

// Auxiliary function
// (S6.2.3/115) - adjust accordingly
double optimistic_median_analysis(const vector<Student_info>& students) {
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades),
            optimistic_median);
  return median(grades);
}

// Output result to compare the two groups of students who did and
// who didn't do all of their homework.
// (S6.2.3/113)
void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt) {
  out << name << ": median(did) = " << analysis(did)
      << ": median(didnt) = " << analysis(didnt) << endl;
  return;
}

// Compare the Grading Scheme
// (S6.2.3/114)
int main() {
  // students who did and didn't do all their homework
  vector<Student_info> did, didnt;

  // read the student records and partition them
  Student_info student;
  while (read(cin, student)) {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  // verify that the analyses will show us something
  if (did.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }
  if (didnt.empty()) {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  // do the analyses
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in",
                 optimistic_median_analysis, did, didnt);

  return 0;
}