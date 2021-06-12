#include <iostream> // cout cin
#include <string>

#include "string_split.h" // split

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
  string s;
  while (std::cin >> s)
    cout << s << endl;
  return 0;
}
