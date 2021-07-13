#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::map;
using std::max;
using std::pair;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // Invariant:   students contains all the student records read so far
  //              maxlen contains the length of the longest name in students

  while (read(cin, record)) {
    // find the length of the longest name
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  map<pair<float, float>, string> gradeMap = {{{0, 60}, "F"},
                                              {{60, 70}, "D"},
                                              {{70, 80}, "C"},
                                              {{80, 90}, "B"},
                                              {{90, 100}, "A"}};

  map<string, int> gradeCounter;

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
    // cout << students[i].name
    //      << string(maxlen + 1 - students[i].name.size(), ' ');

    // compute and write the grade
    try {
      double final_grade = grade(students[i]);
      string letterGrade;

      for (map<pair<float, float>, string>::iterator i = gradeMap.begin();
           i != gradeMap.end(); ++i) {
        if (final_grade >= i->first.first && final_grade < i->first.second) {
          letterGrade = i->second;
          ++gradeCounter[letterGrade];
        }
      }
      // streamsize prec = cout.precision();
      // cout << setprecision(3) << final_grade << setprecision(prec) << "\t"
      //      << letterGrade;
    } catch (domain_error e) {
      cout << e.what();
    }
    // cout << endl;
  }

  cout << "Grade Breakdown" << endl;

  for (map<string, int>::iterator i = gradeCounter.begin();
       i != gradeCounter.end(); ++i) {
    cout << i->first << "\t" << i->second << " student(s)" << endl;
  }
  return 0;
}
