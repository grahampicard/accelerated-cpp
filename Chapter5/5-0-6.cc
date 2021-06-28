#include <iostream>
#include <string>
#include <math.h>
#include <vector>

#include "frames.h"
#include "string_split.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

int main()
{
  string s;

  while (getline(cin, s))
  {
    vector<string> v = split(s);
    v = frame(v);
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
      cout << v[i] << endl;
    }
  }

  return 0;
}

