#include <iostream>
#include <string>
#include <vector>

#include "inputs.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  vector<string> results;
  results = read(cin, results);

  vector<string>::size_type vec_sz;
  vec_sz = results.size();

  cout << "Word count: " << vec_sz << endl;

  return 0;
}
