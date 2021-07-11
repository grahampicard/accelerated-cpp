#include <algorithm>
#include <iostream>
#include <vector>

using std::inserter;
using std::cout;
using std::endl;
using std::back_inserter;
using std::copy;
using std::vector;


int main() {
  vector<int> u(80000000, 10000); 

  // We have to use `back_inserter` which will create a pointer to the end;
  time_t start = time(0);  
  vector<int> v;
  copy(u.begin(), u.end(), back_inserter(v));
  double seconds_since_start = difftime(time(0), start);

  // We can also use `inserter`;
  time_t start2 = time(0);
  vector<int> w;
  copy(u.begin(), u.end(), inserter(w, w.begin()));
  double seconds_since_start2 = difftime(time(0), start2);

  cout << "Back Inserter time: " << seconds_since_start << endl;
  cout << "inserter time: " << seconds_since_start2 << endl;
  // `back_inserter` pros
  //    more performant
  //    easy to change the type of the container
  //    
  // push_back pros
  //    easy to understand
  //    doesn't require the base vector to be complete
  
}