#ifndef GUARD_Grade_check_h
#define GUARD_Grade_check_h

#include <ostream>
#include <string>
#include <vector>

#include "Student_info.h"

using std::ostream;
using std::string;
using std::vector;

double average(const vector<double>& v);

double average_grade(const Student_info& s);

bool did_all_hw(const Student_info& s);

double grade_aux(const Student_info& s);

double optimistic_median(const Student_info& s);

double agnostic_analysis(const vector<Student_info>& students,
                         double analysis(const Student_info& s));

void write_analysis(ostream& out, const string& name,
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt,
                    double analysis(const Student_info& s));
#endif
