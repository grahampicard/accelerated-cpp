#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::accumulate;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string concat(vector<string> v) {
  string result;
  result = accumulate(v.begin(), v.end(), string(""));
  return result;
}

int main() {
  vector<string> v{"this", "is", "a", "string", "vector"};
  string s = concat(v);
  cout << s << endl;
  return 0;
}
