// Section 6-2: Comparing grading schemes
// Pages: 110-116
//
// This problem aims to solve the problem where a student could only do 3
// assignments, then the average / median grade will be high

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::accumulate;
using std::back_inserter;
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::find;
using std::max;
using std::ostream;
using std::remove_copy;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::transform;
using std::vector;

bool did_all_hw(const Student_info &s)
{
  return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double grade_aux(const Student_info &s)
{
  try
  {
    return grade(s);
  }
  catch (domain_error)
  {
    return grade(s.midterm, s.final, 0);
  }
}

double median_analysis(const vector<Student_info> &students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
  return median(grades);
}

double average(const vector<double> &v)
{
  return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

double average_grade(const Student_info &s)
{
  return grade(s.midterm, s.final, average(s.homework));
}

double average_analysis(const vector<Student_info> &students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades),
            average_grade);
  return median(grades);
}

double optimistic_median(const Student_info &s)
{
  vector<double> nonzero;
  remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

  if (nonzero.empty())
    return grade(s.midterm, s.final, 0);
  else 
    return grade(s.midterm, s.final, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info> &students)
{
  vector<double> grades;
  transform(students.begin(), students.end(), back_inserter(grades),
            optimistic_median);
  return median(grades);
}

void write_analysis(ostream &out, const string &name,
                    double analysis(const vector<Student_info> &),
                    const vector<Student_info> &did,
                    const vector<Student_info> &didnt)
{
  out << name << ": median(did) = " << analysis(did) << ", median (didnt) = "
      << analysis(didnt) << endl;
}

int main()
{
  vector<Student_info> did, didnt;
  Student_info student;

  // Invariant:   students contains all the student records read so far
  //              maxlen contains the length of the longest name in students

  while (read(cin, student))
  {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  if (did.empty())
  {
    cout << "No student did all the homework!" << endl;
    return 1;
  }

  if (didnt.empty())
  {
    cout << "Every student did all the the homework!" << endl;
    return 1;
  }

  // do the analyses
  write_analysis(cout, "median", median_analysis, did, didnt);
  write_analysis(cout, "average", average_analysis, did, didnt);
  write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

  return 0;
}
