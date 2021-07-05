// Section 6-1: Analyzing strings
// Pages: 101-103
//
// This example shows how to use `copy` to concatenate two containers.
// It leverages iterators, which are commonly used in C++.

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::string;
using std::vector;

vector<string> vcat(const vector<string> &top, const vector<string> &bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // copy the entire bottom picture
  for (vector<string>::const_iterator it = bottom.begin();
       it != bottom.end(); ++it)
    ret.push_back(*it);

  return ret;
}

vector<string> vcat2(const vector<string> &top, const vector<string> &bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // will insert (at the end of ret) the iterator for bottom's begin and
  // end
  ret.insert(ret.end(), bottom.begin(), bottom.end());
  return ret;
}

vector<string> vcat3(const vector<string> &top, const vector<string> &bottom)
{
  // copy the top picture
  vector<string> ret = top;

  // this doesn't require a method, but rather just uses the iterator 
  // containers. It will start and end at the first two args, and the
  // thrid arg uses `back_inserter` which provides an iterator which 
  // points to the end of ret
  copy(bottom.begin(), bottom.end(), back_inserter(ret));
  return ret;
}

string strVcat3(const string &top, const string &bottom)
{
  // copy the top picture
  string ret = top;

  // this doesn't require a method, but rather just uses the iterator 
  // containers. It will start and end at the first two args, and the
  // thrid arg uses `back_inserter` which provides an iterator which 
  // points to the end of ret
  copy(bottom.begin(), bottom.end(), back_inserter(ret));
  return ret;
}

int main()
{

  vector<string> t = {"a", "b", "c"}, b = {"1", "2", "3"};
  vector<string> result = vcat(t, b);
  vector<string> result2 = vcat2(t, b);
  vector<string> result3 = vcat3(t, b);

  bool pass = true;

  for (vector<string>::size_type i = 0; i < result.size(); ++i) {
    if (result[i] != result2[i])
      pass = false;
    if (result[i] != result3[i])
      pass = false;
  }

  if (pass == true)
    cout << "Passes" << std::endl;
  else
    return 1;

  // let's see if this words with strings, too
  string st = "abc", bt = "123";
  string res = strVcat3(st, bt);
  
  if (res == "abc123")
    cout << "Passes string" << std::endl;
  else
    return 1;

  return 0;
}
