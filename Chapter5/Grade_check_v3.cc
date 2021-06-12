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

  // This implementation uses an interator type, which removes our
  // reliance on indices. In doing so, we initialize iter as an iterator
  // type. In this case, we pass the values of hte iterator to fgrade
  // and in the case we will mutate `students`. An `iterator` denotes
  // a value in a vector, and the dereferenced `*iterator` represents
  // the value at that given iterator.  
  vector<Student_info>::iterator iter = students.begin(); 
  
  while(iter != students.end()) {
    // grade the VALUES of our iterator
    if (fgrade(*iter)) {
      // push back the VALUES of our iterator
      fail.push_back(*iter);
      // erase the element from the students vector
      iter = students.erase(iter);
    } else
      // increase the iterator
      ++iter;
  }
  return fail;
}
