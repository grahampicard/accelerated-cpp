#include <algorithm>
#include <iostream>
#include <vector>

using std::copy;
using std::cout;
using std::vector;

int main() {
  // This will yield a segmentation fault because the pointer of v.begin()
  // will be the same as v.end() and we cand add to it.

  vector<int> u(10, 100);
  vector<int> v;
  copy(u.begin(), u.end(), v.begin());
}