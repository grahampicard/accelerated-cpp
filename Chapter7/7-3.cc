// Generating a cross-reference table
// (S7.3 / 126)

#include <algorithm>  // sort, unique
#include <iostream>   // cin, cout
#include <istream>    // istream
#include <map>        // map
#include <string>     // string
#include <vector>     // vector

#include "string_split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::map;
using std::sort;
using std::string;
using std::unique;
using std::vector;

// declaring xref to use "split" by default, but we can use another
// function to find words. For instance, we could use the find_urls
// function to locate url locations
map<string, vector<int>> xref(
    istream &in, vector<string> find_words(const string &) = split) {
  string line;
  int line_number = 0;

  // our map `ret` will store every word at `first` and a vector of occurences
  // at `second`.
  map<string, vector<int>> ret;

  // read the next line
  while (getline(in, line)) {
    ++line_number;

    // break the input line into words
    vector<string> words = find_words(line);
    sort(words.begin(), words.end());

    for (vector<string>::iterator i = words.begin(); i != words.end(); ++i) {
      if (*i == *(i+1) ) {
        words.erase(i);
        --i;
      }
    }

    // remember that each word occurs on the current line
    for (vector<string>::const_iterator it = words.begin(); it != words.end();
         ++it)
      ret[*it].push_back(line_number);
  }
  return ret;
}

int main() {
  // call xref using split by default
  map<string, vector<int>> ret = xref(cin);

  // write the results

  for (map<string, vector<int>>::const_iterator it = ret.begin();
       it != ret.end(); ++it) {
    // write the word
    cout << it->first << " occurs on line(s):";

    // followed by one or more line numbers
    vector<int>::const_iterator line_it = it->second.begin();
    cout << *line_it;

    ++line_it;
    // write the rest of the line numbers, if any
    while (line_it != it->second.end()) {
      cout << "," << *line_it;
      ++line_it;
    }

    // write a new line to separate each word from the next
    cout << endl;
  }
  return 0;
}
