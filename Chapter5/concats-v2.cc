#include <string>
#include <vector>

#include "frames.h"

using std::string;
using std::vector;

vector<string> vcat(const vector<string>& top,
                    const vector<string>& bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy entire bottom picture
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  
  return ret;
}

vector<string>
hcat(const vector<string>& left, const vector<string>& right)
{
  vector<string> ret;

  // add 1 to leave a space between pictures
  string::size_type width1 = width(left) + 1;

  // indices to look at elements from left and right respectively
  vector<string>::size_type i = 0, j = 0;

  string s;

  // continue until we've seen all rows from both pictures
  while (i != left.size() || j != right.size()) {
    // construct new string to hold characters

    // copy a row from the left-hand side
    if (i != left.size())
      s = left[i++];

    // pad to full width
    s += string(width1 - s.size(), ' ');

    // copy a row from the right-hand side, if there is one
    if (j != right.size())
      s += right[j++];

    // add s to the picture we're creating
    ret.push_back(s);
  }
  return ret;
}