#include <algorithm>
#include <vector>

#include "Student_info.h"
#include "grade.h"

using std::back_inserter;
using std::remove_copy_if;
using std::remove_if;
using std::vector;

bool fgrade(const Student_info& s) { return grade(s) < 60; }

bool pgrade(const Student_info& s) { return !fgrade(s); }

// create a vector of all students who failed, and overwrite
// original vector with all students who passed
vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;
  remove_copy_if(students.begin(), students.end(), back_inserter(fail), pgrade);
  students.erase(remove_if(students.begin(), students.end(), fgrade),
                 students.end());

  return fail;
}
