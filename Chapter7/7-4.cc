// The output produced by the cross-reference program will be ungainly if
// the input file is large. Rewrite the program to break up the output
// if the lines get too long
//
// Generating a cross-reference table
// (S7.3 / 126)

#include <iomanip>   // setw
#include <iostream>  // cin, cout
#include <istream>   // istream
#include <map>       // map
#include <sstream>   // ostringstream
#include <string>    // string
#include <vector>    // vector

#include "string_split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::map;
using std::ostringstream;
using std::setw;
using std::string;
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
  const string::size_type lineLength = 60;

  for (map<string, vector<int>>::const_iterator it = ret.begin();
       it != ret.end(); ++it) {
    
    // let's use ostreamstring to output the data
    ostringstream outputStream;
    vector<int>::const_iterator line_it = it->second.begin();
    outputStream << it->first 
                 << " occurs on line(s):" 
                 << *line_it;
    ++line_it;

    // write the rest of the line numbers, if any
    while (line_it != it->second.end()) {
      outputStream << "," << *line_it;
      ++line_it;
    }

    string outputLine = outputStream.str();
    for (string::size_type i = 0; i != outputLine.size(); i++) {
      if (i % lineLength == 0 ) {
        cout << endl;
      }
      cout << outputLine[i];
    }

    // write a new line to separate each word from the next
    cout << endl;
  }
  return 0;
}
