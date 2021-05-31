#include "inputs.h"

using std::istream;
using std::string;
using std::vector;

vector<string> read(istream& in, vector<string>& results) {

  if (in) {
    string s;
    while (in >> s) results.push_back(s);
    in.clear();
  }
  return results;
}
