// By using a typedef, we can write one version of the program that 
// implements either a vector-based solution or a list-based on. 
// Write and test this version of the program.

#include <algorithm>
#include <iomanip>
#include <ctime>
#include <ios>
#include <iostream>
#include <list>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Grade_check_v4.h"
#include "Student_info.h"

using std::cin;
using std::clock;
using std::cout;
using std::domain_error;
using std::endl;
using std::list;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

// This function extracts the names of all students who failed a given
// assessment it's technically correct, but it has a disadvantage that it
// duplicates data in multiple place. First, it logs all students, then
// it creates pass list and a fail list. It populates both lists,
// then it overwrites the students list with the pas list.

typedef std::vector<Student_info> group;

int main()
{
  group students;
  Student_info record;
  string::size_type maxlen = 0;

  // Invariant:  students contain all the records read so far.
  //             maxlen contains the length of the longest name
  while (read(cin, record))
  {
    maxlen = max(maxlen, record.name.size());
    students.push_back(record);
  }

  // sort values
  sort(students.begin(), students.end(), compare);

  // find all students that have failed
  group fails = extract_fails(students);

  // write the names and grades
  group::iterator iter = fails.begin();
  while (iter != fails.end())
  {
    cout << (*iter).name << endl;
    ++iter;
  }

  return 0;
}
