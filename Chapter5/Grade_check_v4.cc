#include <list>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::list;
using std::vector;

bool fgrade(const Student_info& s) {
  return grade(s) < 60;
}

// using a list instead of an iterator
list<Student_info> extract_fails(list<Student_info>& students) {
  list<Student_info> fail;

  // the value at that given iterator.  
  list<Student_info>::iterator iter = students.begin(); 
  
  while(iter != students.end()) {
    // grade the VALUES of our iterator
    if (fgrade(*iter)) {
      // push back the VALUES of our iterator
      fail.push_back(*iter);
      // erase the element from the students list
      iter = students.erase(iter);
    } else
      // increase the iterator
      ++iter;
  }
  return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
  vector<Student_info> fail;

  // the value at that given iterator.  
  vector<Student_info>::iterator iter = students.begin(); 
  
  while(iter != students.end()) {
    // grade the VALUES of our iterator
    if (fgrade(*iter)) {
      // push back the VALUES of our iterator
      fail.push_back(*iter);
      // erase the element from the students list
      iter = students.erase(iter);
    } else
      // increase the iterator
      ++iter;
  }
  return fail;
}
