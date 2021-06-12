#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::vector;

bool fgrade(const Student_info& s) {
  return grade(s) < 60;
}

// correct but potentially slow 
vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  vector<Student_info>::size_type i = 0;
  
  // this iterates through the students indexes of the students vector
  while(i != students.size()) {
    // grade the elements of each iterator
    if (fgrade(students[i])) {
      // push the values to the fail vector
      fail.push_back(students[i]);
      // erase at the index of the new vector
      students.erase(students.begin() + i);
    } else
      ++i;
  }
  return fail;
}
