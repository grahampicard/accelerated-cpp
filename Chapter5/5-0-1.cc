#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Grade_check.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// This function extracts the names of all students who failed a given
// assessment it's technically correct, but it has a disadvantage that it
// duplicates data in multiple place. First, it logs all students, then
// it creates pass vector and a fail vector. It populates both vectors,
// then it overwrites the students vector with the pas vector.
int main() {
  vector<Student_info> students;
  Student_info record;
  string::size_type maxlen = 0;

  // Invariant:  students contain all the records read so far.
  //             maxlen contains the length of the longest name
  while(read(cin, record)) {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  sort(students.begin(), students.end(), compare);

  // find all students that have failed
  vector<Student_info> fails = extract_fails(students); 

  // write the names and grades
  for (vector<Student_info>::size_type i = 0; i != fails.size(); ++i) {
    cout << fails[i].name << endl;
  }
  return 0;
}
