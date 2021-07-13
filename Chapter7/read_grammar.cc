
#include "read_grammar.h"

#include <istream>
#include <string>
#include <vector>

#include "string_split.h"

using std::istream;
using std::string;
using std::vector;

// first step for the 7-0-3. It reads a category and an input value
// read a grammar from a given input stream
Grammar read_grammar(istream& in) {
  Grammar ret;
  string line;

  // read the input
  while (getline(in, line)) {
    // split the input into words
    vector<string> entry = split(line);
    if (!entry.empty())
      // use the category to store the associated rule
      ret[entry[0]].push_back(Rule(entry.begin() + 1, entry.end()));
  }
  return ret;
}
