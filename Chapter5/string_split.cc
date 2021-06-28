#include <cctype>
#include <string>
#include <vector>

using std::isspace;
using std::string;
using std::vector;

// Breaks a line of inputs into words, separated from each other by
// whitespace (space, tab, backspace, or EOF). It reads characters up to
// the whitespace character.
vector<string> split(const string& s)
{

  // we'll start by defining a string
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  // invariant: we have processed characters [original value of i, i)
  while (i != s.size())
  {
    // ignore leading blanks
    // invariant: characters in range [original i, current i) are all spaces
    while (i != s.size() && isspace(s[i]))
      ++i;

    // find end of next word
    string_size j = i;
    // invariant: none of the characters in the range [original j, current j)
    // is a space
    while (j != s.size() && !isspace(s[j]))
      ++j;

    // if we found some nonwhitespace characters
    if (i != j)
    {
      // copy from s starting at i and taking j - i chars
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }
  return ret;
}
