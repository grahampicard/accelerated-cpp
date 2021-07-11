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

double average_analysis(const vector<Student_info>& students);

bool did_all_hw(const Student_info& s);

double grade_aux(const Student_info& s);

double median_analysis(const vector<Student_info>& students);

double optimistic_median(const Student_info& s);

double optimistic_median_analysis(const vector<Student_info>& students);

void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt);

#endif
