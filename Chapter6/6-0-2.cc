// (S6.1.1 / 103-105)
// Another way to split
//
// Uses `find_if` algorithm, which also leverages iterators
// to reimplement our string split function created in earlier chapters

#include <ctype.h>

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::find_if;
using std::isspace;
using std::string;
using std::vector;

// these are simply rappers for the space functions
bool space(char c)
{
  return isspace(c);
}

bool not_space(char c)
{
  return !isspace(c);
}

// reworking the split function
vector<string> split(const string &str)
{
  // our results vector
  vector<string> ret;

  // we start off by making iterators for our string
  typedef string::const_iterator iter;

  iter i = str.begin();
  while (i != str.end())
  {
    // ignore leading spaces for each search
    i = find_if(i, str.end(), not_space);

    // Find the occurance of `space` within the iterator
    // range specified by `i` and `str.end()`
    iter j = find_if(i, str.end(), space);

    // Materialze the string into the results vector;
    if (i != str.end())
      // `string` is heavily overloaded. It has a declaration, where
      // it will create a string given two iterators and that can be
      // appeneded to our results vector
      ret.push_back(string(i, j));
    i = j;
  }
  return ret;
}

int main()
{
  // testing function for our example
  string testStr = "Let's see how this splits things!";

  vector<string> results = split(testStr);

  if (results.size() != 6)
    cout << "Incorrect size. Expected 6, observed "
         << results.size()
         << std::endl;
  else
    cout << "Passes: Expected 6, observed " << results.size() << endl;

  return 0;
}