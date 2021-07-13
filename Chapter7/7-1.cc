// Introducing maps
// (S7.2 / 124)

#include <algorithm>
#include <iostream>  // cin, cout, endl
#include <map>       // map
#include <string>    // string
#include <vector>    // vector

using std::back_inserter;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::sort;
using std::string;
using std::vector;

bool compare(pair<string, int>& a, pair<string, int>& b) {
  return a.second < b.second;
}

int main() {
  string s;
  map<string, int> counters;  // store each word and an associated counter

  // read the input, keeping track of each word
  while (cin >> s) ++counters[s];

  vector<pair<string, int>> v;

  copy(counters.begin(), counters.end(), back_inserter(v));
  sort(v.begin(), v.end(), compare);

  // write the words and associated counts
  for (vector<pair<string, int>>::const_iterator it = v.begin(); it != v.end();
       ++it) {
    // each element of the map is a `pair`, that has two values
    // `first` and `second`. These are functionally equivalent
    // to keys and values in Python dicts.

    cout << it->first << "\t" << it->second << endl;
  }
  return 0;
}