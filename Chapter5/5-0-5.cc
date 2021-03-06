#include <iostream> // cout cin
#include <string>
#include <stdio.h>
#include <vector>

#include "string_split.h" // split

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
  string s;

  while (getline(cin, s))
  {
    vector<string> v = split(s);
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
      cout << v[i] << endl;
    }
  }

  return 0;
}
