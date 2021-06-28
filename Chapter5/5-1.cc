#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include <stdio.h>

#include "string_split.h"


using std::cin;
using std::cout;
using std::tolower;

using std::endl;
using std::getline;
using std::sort;
using std::string;
using std::vector;

// struct for storing a string and it's start
struct pair {
  string startVal;
  vector<string> str;
};

// sorting the strings
bool compare(const pair& x, const pair& y) { 
  return x.str[0] < y.str[0];
}


int main() {
  vector<pair> allPairs;
  string s;

  while(getline(cin, s))
  {
    // split string and generate iterators
    vector<string> sSplit = split(s);
    vector<string>::iterator cur, end;
    string startVal;
    startVal = *sSplit.begin();
    cur = sSplit.begin();
    end = sSplit.end();
    
    while(cur != end) {
      // create a new pair per permutatoin
      pair p;
      p.startVal = startVal;
      p.str = sSplit;
      allPairs.push_back(p);

      // create next permutation
      sSplit.push_back(*sSplit.begin());
      sSplit.erase(sSplit.begin());
      ++cur;
    }

    // per instructions, sort
    sort(allPairs.begin(), allPairs.end(), compare);

    for (vector<pair>::iterator i = allPairs.begin(); i != allPairs.end(); ++i) {
      // get the separator
      string seperator = (*i).str[0];
      bool addLeft = true;
      vector<string> left, right;

      // re-sort the string
      int j = 0;

      while ((*i).str[0] != (*i).startVal) {
        (*i).str.push_back((*i).str[0]);
        (*i).str.erase((*i).str.begin());
        ++j;
      }

      for (vector<string>::iterator j = (*i).str.begin(); j != (*i).str.end(); ++j) {
        if (*j == seperator)
          addLeft = false;
        if (addLeft) {
          left.push_back(*j);
        } else {
          right.push_back(*j);
        }
      }

      for (vector<string>::iterator j = left.begin(); j != left.end(); ++j) {
        cout << *j << "\t";
      }

      cout << "\t|\t";

      for (vector<string>::iterator j = right.begin(); j != right.end(); ++j) {
        cout << *j << "\t";
      }

      cout << endl;
    }
  }
}
