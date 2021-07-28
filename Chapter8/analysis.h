#ifndef GUARD_Grade_check_h
#define GUARD_Grade_check_h

#include <algorithm>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "Student_info.h"
#include "median.h"

using std::ostream;
using std::string;
using std::vector;
using std::endl;

double average(const vector<double>& v);

bool did_all_hw(const Student_info& s);
double grade_aux(const Student_info& s);
double average_grade(const Student_info& s);
double optimistic_median(const Student_info& s);

template <class Function>
double analysis(const std::vector<Student_info>& students,
                Function grading_function) {
  vector<double> grades;
  std::transform(students.begin(), students.end(), std::back_inserter(grades),
                 grading_function);
  return median(grades);
}

template <class Function>
void write_analysis(ostream& out, const string& name,
                    Function grading_function,
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt) {
  out << name << ": median(did) = " << analysis(did, grading_function)
      << ": median(didnt) = " << analysis(didnt, grading_function) << endl;
}

#endif
